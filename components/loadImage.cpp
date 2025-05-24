#include <opencv2/opencv.hpp>
#include <filesystem>
#include "./header.hpp"

cv::Mat loadImage(std::string path, int pilihan, std::string dir) {
  cv::Mat image = cv::imread("./images/" + path + ".jpeg");
  if (image.empty()) {
    std::cerr << "Gagal memuat gambar: " << path << std::endl;
    return cv::Mat();
  }

  cv::imshow("Original Image", image);
  
  if (pilihan == 2) {
    std::filesystem::create_directories(dir);
    cv::imwrite(dir + "/0_originalImage.jpg", image);
  } 
  
  return image;
}