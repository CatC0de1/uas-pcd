#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

cv::Mat noiseFiltering(const cv::Mat& image, int pilihan, int d, double sigmaColor, double sigmaSpace) {

  cv::Mat filteredImage;

  // Apply bilateral filter
  cv::bilateralFilter(image, filteredImage, d, sigmaColor, sigmaSpace);

  // Display the filtered image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Filtered Image", filteredImage);

  return filteredImage;
}