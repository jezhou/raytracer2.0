#include <iostream>
#include <glm/vec3.hpp>

int main() {
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx <<  " " << ny << "\n255\n";

  for(int y = ny - 1; y >= 0; y--) {
    for(int x = 0; x < nx; x++) {
      float r = float(x) / float(nx);
      float g = float(y) / float(ny);
      float b = 0.2;
      glm::vec3 color(r, g, b);
      std::cout << int(color.r * 255.0) << " " << int(color.g * 255.0) << " " << int(color.b * 255.0) << "\n";
    }
  }
};