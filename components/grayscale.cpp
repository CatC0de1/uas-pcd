#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

// Function to convert an image to grayscale
bool grayscale(const cv::Mat& image, int pilihan) {
  if (image.empty()) {
    std::cerr << "Error: Input image is empty!" << std::endl;
    return false;
  }

  // Convert the image to grayscale
  cv::Mat grayImage;
  cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

  // Display the grayscale image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Grayscale Image", grayImage);

  return true;
}