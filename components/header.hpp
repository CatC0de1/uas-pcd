#ifndef CONVERT_H
#define CONVERT_H

#include <opencv2/opencv.hpp>

bool grayscale(const cv::Mat& image, int pilihan);
bool edgeDetection(const cv::Mat& image, int pilihan);
bool noiseFiltering(const cv::Mat& image, int pilihan);
bool charDetection(const cv::Mat& image, int pilihan);

#endif