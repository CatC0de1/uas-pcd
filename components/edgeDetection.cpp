#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

bool edgeDetection(const cv::Mat& image, int pilihan) {
  // Create a copy of the original image
  cv::Mat edgeImage = image.clone();

  // Convert the image to grayscale
  cv::Mat grayImage;
  cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

  // Apply Canny edge detection
  cv::Canny(grayImage, edgeImage, 100, 200);

  // Display the edge-detected image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Edge Detected Image", edgeImage);

  return true;
}