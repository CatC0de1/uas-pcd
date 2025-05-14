#ifndef CONVERT_H
#define CONVERT_H

#include <opencv2/opencv.hpp>

cv::Mat grayscale(const cv::Mat& image, int pilihan);
cv::Mat edgeDetection(const cv::Mat& image, int pilihan);
cv::Mat noiseFiltering(const cv::Mat& image, int pilihan);
std::vector<std::vector<cv::Point>> findContour(const cv::Mat& edge, int pilihan);
cv::Mat charDetection(const cv::Mat& image, int pilihan);

#endif