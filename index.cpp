#include <opencv2/opencv.hpp>
#include <iostream>
#include "./components/header.hpp"

cv::Mat loadImage() {
  std::string path;
  std::cout << "Masukkan nama file gambar: ";
  std::cin >> path;
  cv::Mat image = cv::imread(path);
  if (image.empty()) {
    std::cerr << "Gagal memuat gambar: " << path << std::endl;
    return cv::Mat();
  }

  cv::imshow("Original Image", image);
  
  return image;
}

int main() {
  int pilihan;

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
        int subpilihan;
        std::cin >> subpilihan;

        if (subpilihan == 1 || subpilihan == 2) {
          cv::Mat image = loadImage();
          cv::Mat grayImage = grayscale(image, subpilihan);
          cv::Mat filteredImage = noiseFiltering(grayImage, subpilihan);
          cv::Mat edgeImage = edgeDetection(filteredImage, subpilihan);
          
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