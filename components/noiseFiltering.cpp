#include <opencv2/opencv.hpp>
#include "header.hpp"

cv::Mat noiseFiltering(const cv::Mat& image, int pilihan, int d, double sigmaColor, double sigmaSpace) {

  cv::Mat filteredImage;

  // Apply bilateral filter
  //d = diameter, forced to be odd by opencv
  //sigmaColor = if the contrast between two neighboring pixel is within range of sigmaColor then it get affected
  //sigmaSpace = how further pixel affected 
                //(also restricted by diameter if sigmaSpace is bigger then the area, then all pixel within diameter get affected)
                //smaller sigmaSpace mean only the center pixel get affected
  cv::bilateralFilter(image, filteredImage, d, sigmaColor, sigmaSpace);

  // Display the filtered image if the user chooses option 2
  if (pilihan == 2) cv::imshow("Filtered Image", filteredImage);

  return filteredImage;
}