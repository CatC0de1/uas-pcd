#ifndef CONVERT_H
#define CONVERT_H

#include <opencv2/opencv.hpp>

cv::Mat loadImage(std::string path, int pilihan, std::string dir);
cv::Mat grayscale(const cv::Mat& image, int pilihan, std::string dir);
cv::Mat noiseFiltering(const cv::Mat& image, int pilihan, int d, double sigmaColor, double sigmaSpace, std::string dir);
cv::Mat edgeDetection(const cv::Mat& image, int pilihan, double lowThreshold, double highThreshold, std::string dir, std::string params);
cv::Mat findContour(const cv::Mat& edge, const cv::Mat& grayscale, int pilihan, std::string dir, std::string params);
cv::Mat showImages(int pilihan, const cv::Mat& original, const cv::Mat& grayscale, const cv::Mat& filtered, const cv::Mat& edge);

#endif