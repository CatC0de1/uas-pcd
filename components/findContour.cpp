#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

std::vector<cv::Mat> findContour(const cv::Mat& edge, const cv::Mat& filtered, int pilihan) {
  std::vector<std::vector<cv::Point>> contours;
  std::vector<cv::Vec4i> hierarchy;
  std::vector<std::vector<cv::Point>> validContours;
  std::vector<cv::Mat> resultROIs;

  // Convert the grayscale filtered image to BGR for color display
  cv::Mat displayImage;
  cv::cvtColor(filtered, displayImage, cv::COLOR_GRAY2BGR);

  cv::findContours(edge, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  for (size_t i = 0; i < contours.size(); ++i) {
    double area = cv::contourArea(contours[i]);
    if (area < 100) continue;

    std::vector<cv::Point> approx;
    cv::approxPolyDP(contours[i], approx, 0.02 * cv::arcLength(contours[i], true), true);

    if (approx.size() == 4 && cv::isContourConvex(approx)) {
      validContours.push_back(approx);

      cv::Rect rect = cv::boundingRect(approx);
      
      // Add aspect ratio check if needed
      double aspectRatio = static_cast<double>(rect.width) / rect.height;
      if (aspectRatio < 2.0 || aspectRatio > 6.0) continue;

      // Save the ROI to implement on tesseract
      resultROIs.push_back(filtered(rect));

      // Highlight the rectangle in red on the color image
      cv::rectangle(displayImage, rect, cv::Scalar(0, 0, 255), 2);
    }
  }

  if (pilihan == 2) {
    cv::imshow("Highlight Plat", displayImage);

    for (size_t i = 0; i < resultROIs.size(); ++i) {
      std::string winName = "ROI " + std::to_string(i);
      cv::imshow(winName, resultROIs[i]);
    }
  }

  return resultROIs;
}
