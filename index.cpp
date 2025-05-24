#include <iostream>
#include <opencv2/opencv.hpp>
#include "./components/header.hpp"
#include "./components/params.hpp"

int main() {

  while (true) {
    std::cout << "\n=== Pengenalan Plat Kendaraan untuk Identifikasi Otomatis ===\n";
    std::cout << "1. Mulai Program\n";
    std::cout << "2. Keluar\n";
    std::cout << "Masukkan pilihan: ";
    int pilihan;
    std::cin >> pilihan;

    switch (pilihan) {
      case 1: {
        std::cout << "\nPilih opsi:\n";
        std::cout << "1. Hasil akhir\n";
        std::cout << "2. Per langkah (termasuk simpan citra)\n";
        std::cout << "Masukan pilihan: ";
        int subpilihan;
        std::cin >> subpilihan;

        if (subpilihan == 1 || subpilihan == 2) {
          std::cout << "Masukkan nama file gambar (contoh: plat1): ";
          std::string path;
          std::cin >> path;

          std::string dir;
          if (subpilihan == 2) dir = "./output/" + path + "/";

          cv::Mat image = loadImage(path, subpilihan, dir);
          if (image.empty()) continue;

          cv::Mat grayImage = grayscale(image, subpilihan, dir);

          std::cout << "\nMasukan parameter diameter (bilangan bulat positif, default=9) : ";
          int d;
          std::cin >> d;
          std::cout << "Masukan parameter sigma color (0-255, default=75) : ";
          double sigmaColor;
          std::cin >> sigmaColor;
          std::cout << "Masukan parameter sigma space (bilangan bulat positif, default=75) : ";
          double sigmaSpace;
          std::cin >> sigmaSpace;
          cv::Mat filteredImage = noiseFiltering(grayImage, subpilihan, d, sigmaColor, sigmaSpace, dir);

          std::string paramNF = "_" + std::to_string(d) + "-" + std::to_string((int)sigmaColor) + "-" + std::to_string((int)sigmaSpace);
          std::cout << "\nMasukan parameter low threshold (0-255, default=50) : ";
          double lowThreshold;
          std::cin >> lowThreshold;
          std::cout << "Masukan parameter high threshold (0-255, default=150) : ";
          double highThreshold;
          std::cin >> highThreshold;
          cv::Mat edgeImage = edgeDetection(filteredImage, subpilihan, lowThreshold, highThreshold, dir, paramNF);

          std::string paramNF_ED = paramNF + "_" + std::to_string((int)lowThreshold) + "-" + std::to_string((int)highThreshold);
          cv::Mat contours = findContour(edgeImage, grayImage, subpilihan, dir, paramNF_ED);
          
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