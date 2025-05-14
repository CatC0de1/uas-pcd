#include <iostream>
#include <opencv2/opencv.hpp>
#include "header.hpp"

std::vector<std::vector<cv::Point>> findContour(const cv::Mat& edge, int pilihan) {
  std::vector<std::vector<cv::Point>> contours; // saved contours
  std::vector<cv::Vec4i> hierarchy; // saved hierarchy of contours

  // find contours
  cv::findContours(edge, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  if (pilihan == 2) {
    // change color to BGR for displaying
    cv::Mat display;
    cv::cvtColor(edge, display, cv::COLOR_GRAY2BGR);

    for (size_t i = 0; i < contours.size(); ++i) {
      double area = cv::contourArea(contours[i]);
      if (area > 100) { // filter small contours
        cv::Rect rect = cv::boundingRect(contours[i]);
        cv::rectangle(display, rect, cv::Scalar(0, 0, 255), 2); // draw rectangle around contour
      }
    }

    cv::imshow("Hasil Kontur (Bounding Box)", display);
  }

  return contours;
}
