#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
  std::cout << "Hello, OpenCV!" << std::endl;
  std::string imagePath = "kucing1.png";
  cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
  cv::imshow("Image", image);
  cv::waitKey(0);

  return 0;
}