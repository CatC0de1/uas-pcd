#ifndef CONVERT_H
#define CONVERT_H

#include <opencv2/opencv.hpp>

cv::Mat grayscale(const cv::Mat& image, int pilihan);
cv::Mat noiseFiltering(const cv::Mat& image, int pilihan, int d, double sigmaColor, double sigmaSpace);
cv::Mat edgeDetection(const cv::Mat& image, int pilihan, double lowThreshold, double highThreshold);
cv::Mat findContour(const cv::Mat& edge, const cv::Mat& filtered, int pilihan);

#endif