#include "Utilities.h"
#include "TestApp.h"

const std::string DATA_PATH = "images\\";
const std::string RESULTS_PATH = "results\\";

int main() {
    std::cout << "OpenCV version is " << CV_VERSION << std::endl;

    std::unique_ptr<Utilities> util = std::make_unique<Utilities>();
    try {
      std::string imagePath = "number_zero.jpg";

      /* Read image in Grayscale format
         Flags
          IMREAD_GRAYSCALE or 0: Loads image in grayscale mode
          IMREAD_COLOR or 1: Loads a color image. Any transparency of image will be neglected. It is the default flag.
          IMREAD_UNCHANGED or -1: Loads image as such including alpha channel.
      */
      cv::Mat testImage = cv::imread(DATA_PATH + imagePath, 0);
      util->DisplayImageInWindow("Number 0", testImage, false);
      std::cout << testImage << std::endl;

      /* Get image properties */
      util->DisplayImageProperties(testImage);

      /** Manipulating Pixels **/
      /* Access specific pixels */
      std::cout << (int)testImage.at<uchar>(0, 0);

      /* Modify specific pixels */
      testImage.at<uchar>(0, 0) = 200;
      std::cout << testImage << std::endl;
      std::cout << "Original Matrix\n" << testImage << std::endl;

      /** Manipulating Groups of Pixels **/
      /* Access a region */
      cv::Mat test_roi = testImage(cv::Range(0, 2), cv::Range(0, 4));
      std::cout << "Selected Region\n" << test_roi << std::endl;

      /* Modifying a region */
      testImage(cv::Range(0, 2), cv::Range(0, 4)).setTo(111);
      std::cout << "Modified Matrix\n" << testImage << std::endl;

      /* Writing an image to disk */
      imwrite("test.jpg", testImage);

      /** Color Images **/
      // Path of the image to be loaded
      // Here we are supplying a relative path
      std::string muskImagePath = "musk.jpg";

      // Read the image, get properties
      cv::Mat img = cv::imread(DATA_PATH + muskImagePath);
      util->DisplayImageProperties(img);
      util->DisplayImageInWindow("Elon Musk", img, false);

      /* Show the channels */
      cv::Mat imgChannels[3];
      cv::split(img, imgChannels);

      // RGB Channels
      util->DisplayImageInWindow("Elon Musk Red Channel", imgChannels[0], false);
      util->DisplayImageInWindow("Elon Musk Green Channel", imgChannels[1], false);
      util->DisplayImageInWindow("Elon Musk Blue Channel", imgChannels[2], false);

      /** Manipulating Color Pixels **/
      /* Access Color Pixel */
      std::cout << img.at<cv::Vec3b>(0, 0);

      img.at<cv::Vec3b>(0, 0) = cv::Vec3b(0, 255, 255);
      util->DisplayImageInWindow("Elon Musk Yellow Pixel", img, false);

      img.at<cv::Vec3b>(1, 1) = cv::Vec3b(255, 255, 0);
      util->DisplayImageInWindow("Elon Musk Cyan Pixel", img, false);

      img.at<cv::Vec3b>(2, 2) = cv::Vec3b(255, 0, 255);
      util->DisplayImageInWindow("Elon Musk Magenta Pixel", img, false);

      /* Modify Region of Interest */
      img(cv::Range(0, 30), cv::Range(0, 30)).setTo(cv::Scalar(255, 0, 0));
      img(cv::Range(30, 60), cv::Range(0, 30)).setTo(cv::Scalar(0, 255, 0));
      img(cv::Range(240, 270), cv::Range(270, 300)).setTo(cv::Scalar(0, 0, 255));
      util->DisplayImageInWindow("Elon Musk Region of Interest", img, false);

      // Read the image
      // Note that we are passing flag = -1 while reading the image ( it will read the image as is)
      // Path of the PNG image to be loaded
      imagePath = "panther.png";
      cv::Mat imgPNG = cv::imread(DATA_PATH + imagePath, -1);
      util->DisplayImageProperties(imgPNG);

      cv::Mat imgBGR;
      cv::Mat imgPNGChannels[4];
      split(imgPNG, imgPNGChannels);
      merge(imgPNGChannels, 3, imgBGR);

      cv::Mat imgMask = imgPNGChannels[3];
      util->DisplayImageInWindow("Panther Mask", imgMask, false);

    }
    catch (std::exception& e)
    {
        std::cerr << "Caught " << e.what() << std::endl;
        std::cerr << "Type " << typeid(e).name() << std::endl;
    };

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
