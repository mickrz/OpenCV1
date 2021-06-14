#include "Utilities.h"
#include <sstream>

const std::string RESULTS_PATH = "results\\";

/* Image Properties */
const std::string Utilities::Type2Str(const int type) {
    std::string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
    }

    r += "C";
    r += (chans + '0');

    return r;
}

const void Utilities::DisplayImageProperties(const std::string name, const cv::Mat mat)
{
    double minVal, maxVal;
    cv::minMaxLoc(mat, &minVal, &maxVal);

    std::stringstream ss;
    ss << "Window name = " << name
       << "\n\tData type = " << Type2Str(mat.type())
       << "\n\tImage Dimensions = " << mat.size()
       << "\n\tnumber of channels = " << mat.channels()
       << "\n\tBrightness Image Highest Pixel Intensity (min/max) = "
       << minVal << "/" << maxVal;
    std::cout << ss.str() << std::endl;
}

const void Utilities::LoadImageInWindow(const std::string name, cv::Mat &mat)
{
    mat = cv::imread(name);
    DisplayImageInWindow(name, mat, false);
}

const void Utilities::DisplayImageInWindow(const std::string name, const cv::Mat mat, const bool write) {
    imshow(name, mat);
    cv::namedWindow(name, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO | cv::WINDOW_GUI_EXPANDED);
    DisplayImageProperties(name, mat);
    if (write) {
        imwrite(RESULTS_PATH + name + ".png", mat);
    }
}

// Multiply with scaling factor to increase contrast
const cv::Mat Utilities::Contrast(const cv::Mat mat, const double contrastPercentage) {
    // Convert contrastHigh to float
    cv::Mat contrast = mat.clone();
    contrast.convertTo(contrast, CV_64F);
    contrast = contrast * (1 + contrastPercentage / 100.0);
    return contrast;
}

// Add the offset for increasing brightness
const cv::Mat Utilities::Brighten(const cv::Mat mat, const int brightnessOffset) {
    cv::Mat brightHigh = mat.clone();
    cv::Mat brightHighChannels[3];
    split(brightHigh, brightHighChannels);

    for (int i = 0; i < 3; i++) {
        add(brightHighChannels[i], brightnessOffset, brightHighChannels[i]);
    }

    merge(brightHighChannels, 3, brightHigh);
    return brightHigh;
}

// control contrast & brightness
// https://docs.opencv.org/4.1.0/d3/dc1/tutorial_basic_linear_transform.html
const cv::Mat Utilities::PixelTransform(const cv::Mat image, const double alpha, const int beta) {
    cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

    //image.convertTo(new_image, -1, alpha, beta);
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < image.channels(); c++) {
                new_image.at<cv::Vec3b>(y, x)[c] =
                    cv::saturate_cast<uchar>(alpha * image.at<cv::Vec3b>(y, x)[c] + beta);
            }
        }
    }
    return new_image;
}

const cv::Mat Utilities::GammaCorrect(const cv::Mat img, const double gamma)
{
    cv::Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
    cv::Mat res = img.clone();
    LUT(img, lookUpTable, res);
    return res;
}
