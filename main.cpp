#include <opencv2/opencv.hpp>
#include <iostream>
#include "./components/header.hpp"

cv::Mat loadImage(int pilihan) {
  std::string path;
  std::cout << "Masukkan nama file gambar: ";
  std::cin >> path;
  cv::Mat image = cv::imread(path);
  if (image.empty()) {
    std::cerr << "Gagal memuat gambar: " << path << std::endl;
    return cv::Mat();
  }

  if (pilihan == 2) {
    cv::imshow("Original Image", image);
    std::cout << "Seret jendela gambar untuk melihat gambar yang lain.\n";
  }
  
  return image;
}

int main() {
  int pilihan;

  while (true) {
    std::cout << "=== Pengenalan Plat Kendaraan untuk Identifikasi Otomatis ===\n";
    std::cout << "1. Mulai Program\n";
    std::cout << "2. Keluar\n";
    std::cout << "Masukkan pilihan: ";
    std::cin >> pilihan;

    switch (pilihan) {
      case 1: {
        std::cout << "Pilih opsi:\n";
        std::cout << "1. Hasil akhir\n";
        std::cout << "2. Per langkah\n";
        std::cout << "Masukan pilihan: ";
        std::cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
          cv::Mat image = loadImage(pilihan);
          if (image.empty()) {
            std::cerr << "Gambar tidak valid. Kembali ke menu utama.\n";
            break;
          }

          grayscale(image, pilihan);
          edgeDetection(image, pilihan);
          noiseFiltering(image, pilihan);

          std::cout << "Tekan ESC pada gambar untuk kembali ke menu utama.\n";
          
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