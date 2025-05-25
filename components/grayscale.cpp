#include <opencv2/opencv.hpp>
#include "header.hpp"

// Function to convert an image to grayscale
cv::Mat grayscale(const cv::Mat& image, int pilihan, std::string dir) {

  // Convert the image to grayscale using Weighted Average
  // 0.299*R + 0.587*G + 0.114*B
  cv::Mat grayImage;
  cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

  // Display the grayscale image if the user chooses option 2
  if (pilihan == 2) {
    cv::imwrite(dir + "1_grayscale.jpg", grayImage);
  }

  return grayImage;
}