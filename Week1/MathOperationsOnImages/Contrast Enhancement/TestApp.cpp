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
      double contrastPercentage = 30.0;
      cv::Mat contrastHigh = image.clone();

      contrastHigh = util->Contrast(contrastHigh, contrastPercentage);
      util->DisplayImageInWindow("highContrast", contrastHigh);
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
