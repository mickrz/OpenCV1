#include "Utilities.h"
#include "TestApp.h"

const std::string DATA_PATH = "images\\";
const std::string RESULTS_PATH = "results\\";

int main() {
  std::cout << "OpenCV version is " << CV_VERSION << std::endl;
  std::unique_ptr<Utilities> util = std::make_unique<Utilities>();

  try {
    double gamma = 1.5;

    cv::Mat image;
    util->LoadImageInWindow(DATA_PATH + "boy.jpg", image);
    cv::Mat gammaCorrected = util->GammaCorrect(image, gamma);
    util->DisplayImageInWindow("gammaCorrection.png", gammaCorrected);
  }
  catch (std::exception& e) {
    std::cerr << "Caught " << e.what() << std::endl;
    std::cerr << "Type " << typeid(e).name() << std::endl;
  };

  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
