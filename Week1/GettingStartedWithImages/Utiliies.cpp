#include "Utilities.h"

const std::string RESULTS_PATH = "results\\";

/* Image Properties */
std::string Utilities::Type2Str(int type) {
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

void Utilities::DisplayImageProperties(cv::Mat mat)
{
    double minVal, maxVal;
    std::cout << "Data type = " << Type2Str(mat.type()) << std::endl;
    std::cout << "Image Dimensions = " << mat.size() << std::endl;
    std::cout << "number of channels = " << mat.channels() << std::endl;
    cv::minMaxLoc(mat, &minVal, &maxVal);
    std::cout << "Brightness Image Highest Pixel Intensity : " << maxVal << std::endl;
}

void Utilities::DisplayImageInWindow(std::string name, cv::Mat mat, bool write) {
    imshow(name, mat);
    cv::namedWindow(name, cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO | cv::WINDOW_GUI_EXPANDED);
    if (write) {
        imwrite(RESULTS_PATH + name, mat);
    }
}

// Multiply with scaling factor to increase contrast
cv::Mat Utilities::BruteforceConstrast(cv::Mat mat, double contrastPercentage) {
    // Convert contrastHigh to float
    mat.convertTo(mat, CV_64F);
    mat = mat * (1 + contrastPercentage / 100.0);
    return mat;
}

// Add the offset for increasing brightness
cv::Mat Utilities::BruteforceBrightness(cv::Mat mat, int brightnessOffset) {
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
cv::Mat Utilities::PixelTransform(cv::Mat image, double alpha, int beta) {
    cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());

    image.convertTo(new_image, -1, alpha, beta);
    /*for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < image.channels(); c++) {
                new_image.at<cv::Vec3b>(y, x)[c] =
                    cv::saturate_cast<uchar>(alpha * image.at<cv::Vec3b>(y, x)[c] + beta);
            }
        }
    }*/
    return new_image;
}


cv::Mat Utilities::GammaCorrect(cv::Mat img, double gamma)
{
    cv::Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
    cv::Mat res = img.clone();
    LUT(img, lookUpTable, res);
    return res;
}

