#include <opencv2/opencv.hpp>
#include <iostream>
#include "./components/header.hpp"

cv::Mat loadImage() {
  std::string path;
  std::cout << "Masukkan nama file gambar: ";
  std::cin >> path;
  cv::Mat image = cv::imread("./images/" + path + ".jpeg");
  if (image.empty()) {
    std::cerr << "Gagal memuat gambar: " << path << std::endl;
    return cv::Mat();
  }

  cv::imshow("Original Image", image);
  
  return image;
}

int main() {
  int pilihan;
  int subpilihan;

  int d;
  double sigmaColor;
  double sigmaSpace;
  double lowThreshold;
  double highThreshold;

  while (true) {
    std::cout << "\n=== Pengenalan Plat Kendaraan untuk Identifikasi Otomatis ===\n";
    std::cout << "1. Mulai Program\n";
    std::cout << "2. Keluar\n";
    std::cout << "Masukkan pilihan: ";
    std::cin >> pilihan;

    switch (pilihan) {
      case 1: {
        std::cout << "\nPilih opsi:\n";
        std::cout << "1. Hasil akhir\n";
        std::cout << "2. Per langkah\n";
        std::cout << "Masukan pilihan: ";
        std::cin >> subpilihan;

        if (subpilihan == 1 || subpilihan == 2) {
          cv::Mat image = loadImage();
          cv::Mat grayImage = grayscale(image, subpilihan);

          std::cout << "\nMasukan parameter diameter (bilangan bulat positif, default=9) : ";
          std::cin >> d;
          std::cout << "Masukan parameter sigma color (0-255, default=75) : ";
          std::cin >> sigmaColor;
          std::cout << "Masukan parameter sigma space (bilangan bulat positif, default=75) : ";
          std::cin >> sigmaSpace;
          cv::Mat filteredImage = noiseFiltering(grayImage, subpilihan, d, sigmaColor, sigmaSpace);

          std::cout << "\nMasukan parameter low threshold (0-255, default=50) : ";
          std::cin >> lowThreshold;
          std::cout << "Masukan parameter high threshold (0-255, default=150) : ";
          std::cin >> highThreshold;
          cv::Mat edgeImage = edgeDetection(filteredImage, subpilihan, lowThreshold, highThreshold);

          cv::Mat contours = findContour(edgeImage, filteredImage, subpilihan);
          
          std::cout << "\nTekan ESC pada gambar untuk kembali ke menu utama.\n";
          std::cout << "Seret jendela gambar untuk melihat gambar yang lain.\n";
          
          while (true) {
            int key = cv::waitKey(50);
            if (key == 27) { // ESC key
              cv::destroyAllWindows();
              break;
            }
          }
          
        } else {
          std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
        break;
      }
      case 2:
        std::cout << "Keluar dari program.\n";
        return 0;
      default:
        std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        break;
    }
  }

  return 0;
}