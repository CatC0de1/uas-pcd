#include <opencv2/opencv.hpp>
#include "header.hpp"

cv::Mat findContour(const cv::Mat& edge, const cv::Mat& filtered, int pilihan, std::string dir, std::string params) {
  // Vector to store all detected contours
  std::vector<std::vector<cv::Point>> contours;
  
  // Find all external contours in the edge image
  // RETR_EXTERNAL: retrieves only the extreme outer contours
  // CHAIN_APPROX_SIMPLE: compresses horizontal, vertical, and diagonal segments
  cv::findContours(edge, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  cv::Mat displayImage;
  if (pilihan == 2) cv::cvtColor(filtered, displayImage, cv::COLOR_GRAY2BGR); // Convert to BGR color for drawing colored rectangles

  for (const auto& contour : contours) {
    // Skip small contours (noise) with area less than 100 pixels
    if (cv::contourArea(contour) < 100) continue;

    // Approximate contour to polygon with specified precision
    // 0.02 * arcLength (epsilon is 2% of the contour perimeter)
    std::vector<cv::Point> approx;
    cv::approxPolyDP(contour, approx, 0.02 * cv::arcLength(contour, true), true);

    // Check if the approximated polygon has 4 sides (quadrilateral) and is convex
    if (approx.size() == 4 && cv::isContourConvex(approx)) {
      // Get the bounding rectangle of the contour
      cv::Rect rect = cv::boundingRect(approx);
      
      double aspectRatio = static_cast<double>(rect.width) / rect.height;

      if (aspectRatio >= 2.0 && aspectRatio <= 6.0) {
        // Display the highlighted image if the user chooses option 2
        if (pilihan == 2) {
          cv::rectangle(displayImage, rect, cv::Scalar(0, 0, 255), 2);
          cv::imshow("Highlight Plat", displayImage);
          cv::imwrite(dir + "4_highlightedPlat" + params + ".jpg", displayImage);
        }
        
        // Extract the Region of Interest (ROI) from the filtered image
        cv::Mat ROI = filtered(rect).clone();
        
        // Display the ROI if it's not empty
        if (!ROI.empty()) {
          cv::imshow("ROI", ROI);
          
          if (pilihan == 2) cv::imwrite(dir + "5_ROI" + params + ".jpg", ROI);
        }
        
        return ROI;
      }
    }
  }
  
  return cv::Mat();
}