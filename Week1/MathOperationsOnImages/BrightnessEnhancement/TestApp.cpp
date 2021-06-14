#include "Utilities.h"
#include "TestApp.h"

const std::string DATA_PATH = "images\\";
const std::string RESULTS_PATH = "results\\";

int main() {
    std::cout << "OpenCV version is " << CV_VERSION << std::endl;
    std::unique_ptr<Utilities> util = std::make_unique<Utilities>();

  try {
    cv::Mat image;
    util->LoadImageInWindow(DATA_PATH + "boy.jpg", image);
    int brightnessOffset = 50;
     
    cv::Mat brightHigh = util->Brighten(image, brightnessOffset);
    util->DisplayImageInWindow("highBrightness.png", brightHigh);
  }
  catch (std::exception& e) {
    std::cerr << "Caught " << e.what() << std::endl;
    std::cerr << "Type " << typeid(e).name() << std::endl;
  };

  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
