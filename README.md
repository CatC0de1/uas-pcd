# License Plate Recognition with OpenCV

This project demonstrates a simple license plate recognition system using OpenCV in C++. The program follows these steps:

1. **Convert to Grayscale**: The input image is converted to grayscale.
2. **Filtering**: Noise is reduced using filtering techniques.
3. **Crop License Plate**: The license plate region is detected and cropped.
4. **Predict License Plate**: The cropped region is passed to a model for license plate prediction.

## Requirements

- OpenCV 4.5.5 or higher
- CMake
- MinGW (for Windows)

## How to Build and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/CatC0de1/uas-pcd.git
2. Create a build directory and generate the      
   build files:
   ```bash
   cmake -G "MinGW Makefiles" -B build
3. Build the project:
   ```bash
   cmake --build build
4. Run the executable:
   ```bash
   ./build/App.exe