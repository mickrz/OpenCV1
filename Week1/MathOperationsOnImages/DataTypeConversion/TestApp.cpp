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
    double scalingFactor = 1 / 255.0;
    double shift = 0;

    //Converting from unsigned char to float(32bit)
    image.convertTo(image, CV_32FC3, scalingFactor, shift);

    //Converting from float to unsigned char
    image.convertTo(image, CV_8UC3, 1.0 / scalingFactor, -shift / scalingFactor);
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
