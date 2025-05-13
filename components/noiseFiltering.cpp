#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

bool noiseFiltering(const cv::Mat& image, int pilihan) {
  if (image.empty()) {
    std::cerr << "Error: Input image is empty!" << std::endl;
    return false;
  }

  // Create a copy of the original image
  cv::Mat filteredImage = image.clone();

  // Apply Gaussian blur to the image
  cv::GaussianBlur(image, filteredImage, cv::Size(5, 5), 0);

  // Display the filtered image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Filtered Image", filteredImage);

  return true;
}