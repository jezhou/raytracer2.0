#include <iostream>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Ray.h"

glm::vec3 color(Ray& ray) {
  glm::vec3 unitDirection = glm::normalize(ray.getDirection());
  float t = 0.5f * unitDirection.y + 1.0f;
  return (1.0f - t) * glm::vec3(1.0, 1.0, 1.0) + t * glm::vec3(0.5, 0.7, 1.0);
}

int main() {
  int nx = 200;
  int ny = 100;

  glm::vec3 cameraOrigin(0, 0, 0);
  Camera camera(1.0f, cameraOrigin);

  // Up to down, Right to left
  std::cout << "P3\n" << nx <<  " " << ny << "\n255\n";
  for(int y = -50; y < 50; y++) {
    for(int x = -100; x < 100; x++) {
      Ray ray = camera.shoot(x, y);
      glm::vec3 colorRay = color(ray);
      std::cout << int(colorRay.r * 255.0) << " " << int(colorRay.g * 255.0) << " " << int(colorRay.b * 255.0) << "\n";
    }
  }
};