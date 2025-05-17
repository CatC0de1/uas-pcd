#include <opencv2/opencv.hpp>
#include "header.hpp"

cv::Mat edgeDetection(const cv::Mat& image, int pilihan, double lowThreshold, double highThreshold) {

  cv::Mat edgeImage;

  // Apply Canny edge detection
  // lowThreshold = nilai piksel dibawah ini akan diabaikan
  // highThreshold = nilai piksel diatas ini dianggap edge
  // In between = Nilai diantara dua itu, jika piksel :
  // - Masih tersambung dengan piksel dengan nilai diatas highThreshold maka dianggap edge
  // - Jika tidak connected maka tidak dianggap 
  cv::Canny(image, edgeImage, lowThreshold, highThreshold);

  // Display the edge-detected image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Edge Detected Image", edgeImage);

  return edgeImage;
}