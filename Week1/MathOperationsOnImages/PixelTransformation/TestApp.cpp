#include "Utilities.h"
#include "TestApp.h"

const std::string DATA_PATH = "images\\";
const std::string RESULTS_PATH = "results\\";

int main() {
  std::cout << "OpenCV version is " << CV_VERSION << std::endl;
  std::unique_ptr<Utilities> util = std::make_unique<Utilities>();

  try {
    double alpha = 1.5; /* Simple contrast control */
    int beta = 10;      /* Simple brightness control */

    cv::Mat image;
    util->LoadImageInWindow(DATA_PATH + "boy.jpg", image);
    cv::Mat pixelTransform = util->PixelTransform(image, alpha, beta);
    util->DisplayImageInWindow("pixelTransform.png", pixelTransform);
  }
  catch (std::exception& e) {
    std::cerr << "Caught " << e.what() << std::endl;
    std::cerr << "Type " << typeid(e).name() << std::endl;
  };

  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
