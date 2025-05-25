#include <opencv2/opencv.hpp>
#include <iostream>
#include "./header.hpp"

cv::Mat showImages(int pilihan, const cv::Mat& original, const cv::Mat& grayscale, const cv::Mat& filtered, const cv::Mat& edge) {
  cv::imshow("Original Image", original);
  
  if (pilihan == 2) {
    cv::imshow("Grayscale Image", grayscale);
    cv::imshow("Filtered Image", filtered);
    cv::imshow("Edge Detected Image", edge);
  }
  
  std::cout << "\nTekan ESC pada gambar untuk kembali ke menu utama.\n";
  std::cout << "Seret jendela gambar untuk melihat gambar yang lain.\n";

  while (true) {
    int key = cv::waitKey(50);
    if (key == 27) { // ESC key
      cv::destroyAllWindows();
      break;
    }
  }

  return cv::Mat();
}
