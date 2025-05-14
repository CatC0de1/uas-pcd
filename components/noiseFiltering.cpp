#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

cv::Mat noiseFiltering(const cv::Mat& image, int pilihan) {

  cv::Mat filteredImage;

  int d = 9; // Diameter of the pixel neighborhood
  double sigmaColor = 75; // Filter sigma in color space
  double sigmaSpace = 75; // Filter sigma in coordinate space

  // Apply bilateral filter
  cv::bilateralFilter(image, filteredImage, d, sigmaColor, sigmaSpace);

  // Display the filtered image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Filtered Image", filteredImage);

  return filteredImage;
}