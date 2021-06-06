#include "Utilities.h"
#include "TestApp.h"

const std::string DATA_PATH = "images\\";
const std::string RESULTS_PATH = "results\\";

int main() {
    std::cout << "OpenCV version is " << CV_VERSION << std::endl;

    std::unique_ptr<Utilities> util = std::make_unique<Utilities>();
    try {
      /** Create new images **/
      // Read image
      cv::Mat image;
      util->LoadImageInWindow(DATA_PATH + "boy.jpg", image);

      /* Create copy of new image */
      // Create a new image by copying the already present image using the clone operation
      cv::Mat imageCopy = image.clone();

      /* Create an empty matrix with size (100,200) with black pixels */
      cv::Mat emptyMatrix = cv::Mat(100, 200, CV_8UC3, cv::Scalar(0, 0, 0));
      util->DisplayImageInWindow("emptyMatrix", emptyMatrix);

      /* change black to white pixels */
      emptyMatrix.setTo(cv::Scalar(255, 255, 255));
      util->DisplayImageInWindow("emptyMatrixWhite", emptyMatrix);

      /* Create empty matrix same size as original image */
      cv::Mat emptyOriginal = cv::Mat(emptyMatrix.size(), emptyMatrix.type(), cv::Scalar(100, 100, 100));
      util->DisplayImageInWindow("emptyMatrix100", emptyOriginal);

      /** Cropping an Image Section **/
      // Crop out a rectangle of boy's face
      // x coordinates = 170 to 320
      // y coordinates = 40 to 200
      cv::Mat crop = image(cv::Range(40, 200), cv::Range(180, 320));
      util->DisplayImageInWindow("crop", crop);

      /** Copying a region to another **/
      // First create a copy of the original image 
      cv::Mat copiedImage = image.clone();
      cv::Mat copyRoi = image(cv::Range(40, 200), cv::Range(180, 320));

      // Find height and width of the ROI
      int roiHeight = copyRoi.size().height;
      int roiWidth = copyRoi.size().width;

      // Copy to left of Face
      copyRoi.copyTo(copiedImage(cv::Range(40, 40 + roiHeight), cv::Range(10, 10 + roiWidth)));
      // Copy to right of Face
      copyRoi.copyTo(copiedImage(cv::Range(40, 40 + roiHeight), cv::Range(330, 330 + roiWidth)));

      util->DisplayImageInWindow("copiedRegions", copiedImage);

      /** Resizing an image **/
      /* Method 1 - Specify width and height */
      int resizeDownWidth = 300;
      int resizeDownHeight = 200;
      cv::Mat resizedDown;
      resize(image, resizedDown, cv::Size(resizeDownWidth, resizeDownHeight), 0.0, 0.0, cv::INTER_LINEAR);

      // Mess up with the aspect ratio
      int resizeUpWidth = 600;
      int resizeUpHeight = 900;
      cv::Mat resizedUp;
      resize(image, resizedUp, cv::Size(resizeUpWidth, resizeUpHeight), 0.0, 0.0, cv::INTER_LINEAR);

      util->DisplayImageInWindow("resizedUp", resizedUp);
      util->DisplayImageInWindow("resizedDown", resizedDown);

      /* Method2 - Specify scaling factor */
      // Scaling Down the image 1.5 times by specifying both scaling factors
      double scaleUpX = 1.5;
      double scaleUpY = 1.5;

      // Scaling Down the image 0.6 times specifying a single scale factor.
      double scaleDown = 0.6;

      cv::Mat scaledUp, scaledDown;

      resize(image, scaledDown, cv::Size(), scaleDown, scaleDown, cv::INTER_LINEAR);
      resize(image, scaledUp, cv::Size(), scaleUpX, scaleUpY, cv::INTER_LINEAR);

      util->DisplayImageInWindow("scaledUp", scaledUp);
      util->DisplayImageInWindow("scaledDown", scaledDown);

      /** Creating an Image Mask */
      /* Create a mask using coordinates */
      // Create an empty image of same size as the original
      cv::Mat mask1 = cv::Mat::zeros(image.size(), image.type());
      util->DisplayImageInWindow("mask1", mask1);

      mask1(cv::Range(50, 200), cv::Range(170, 320)).setTo(255);
      util->DisplayImageInWindow("mask1Revised", mask1);

      /* Create a mask using pixel intensity or color */
      cv::Mat mask2;
      inRange(image, cv::Scalar(0, 0, 150), cv::Scalar(100, 100, 255), mask2);
      util->DisplayImageInWindow("mask2", mask2);
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
