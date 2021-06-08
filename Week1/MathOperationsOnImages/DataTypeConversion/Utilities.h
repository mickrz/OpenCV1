#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

class Utilities 
{
public:
	Utilities() = default;
	virtual ~Utilities() = default;

	virtual const std::string Type2Str(const int type);
  virtual const void LoadImageInWindow(const std::string name, cv::Mat &mat);
	virtual const void DisplayImageProperties(const std::string name, const cv::Mat mat);
	virtual const void DisplayImageInWindow(const std::string name, const cv::Mat mat, const bool write=true);
	virtual const cv::Mat BruteforceConstrast(const cv::Mat mat, const double contrastPercentage);
	virtual const cv::Mat BruteforceBrightness(const cv::Mat mat, const int brightnessOffset);
	virtual const cv::Mat PixelTransform(const cv::Mat image, const double alpha, const int beta);
	virtual const cv::Mat GammaCorrect(const cv::Mat image, const double gamma);
};