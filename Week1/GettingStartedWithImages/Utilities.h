#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

class Utilities 
{
public:
	Utilities() = default;
	virtual ~Utilities() = default;

	virtual std::string Type2Str(int type);
	virtual void DisplayImageProperties(cv::Mat mat);
	virtual void DisplayImageInWindow(std::string name, cv::Mat mat, bool write=true);
	virtual cv::Mat BruteforceConstrast(cv::Mat mat, double contrastPercentage);
	virtual cv::Mat BruteforceBrightness(cv::Mat mat, int brightnessOffset);
	virtual cv::Mat PixelTransform(cv::Mat image, double alpha, int beta);
	virtual cv::Mat GammaCorrect(cv::Mat image, double gamma);
};