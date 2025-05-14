#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

cv::Mat edgeDetection(const cv::Mat& image, int pilihan) {

  cv::Mat edgeImage;

  double lowThreshold = 50; // Lower threshold for Canny edge detection
  double highThreshold = 150; // Upper threshold for Canny edge detection

  // Apply Canny edge detection
  cv::Canny(image, edgeImage, lowThreshold, highThreshold);

  // Display the edge-detected image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Edge Detected Image", edgeImage);

  return edgeImage;
}