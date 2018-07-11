#include <iostream>

int main() {
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx <<  " " << ny << "\n255\n";

  for(int y = ny - 1; y >= 0; y--) {
    for(int x = 0; x < nx; x++) {
      float r = float(x) / float(nx);
      float g = float(y) / float(ny);
      float b = 0.2;
      std::cout << int(r * 255.0) << " " << int(g * 255.0) << " " << int(b * 255.0) << "\n";
    }
  }
};