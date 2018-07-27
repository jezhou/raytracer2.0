#include <iostream>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"

glm::vec3 color(Sphere& sphere, Ray& ray) {
  if(sphere.intersection(ray)) {
    return glm::vec3(1, 0, 0);
  };

  return glm::vec3(0, 0, 0);
}

int main() {
  int nx = 200;
  int ny = 100;

  glm::vec3 cameraOrigin(0, 0, 0);
  glm::vec3 sphereOrigin(0, 0, -1.0);
  Camera camera(1.0f, cameraOrigin);
  Sphere sphere(sphereOrigin, 1.0);

  // Up to down, Right to left
  std::cout << "P3\n" << nx <<  " " << ny << "\n255\n";
  for(int y = -50; y < 50; y++) {
    for(int x = -100; x < 100; x++) {
      Ray ray = camera.shoot(x, y);
      glm::vec3 colorRay = color(sphere, ray);
      std::cout << int(colorRay.r * 255.0) << " " << int(colorRay.g * 255.0) << " " << int(colorRay.b * 255.0) << "\n";
    }
  }
}