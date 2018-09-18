#include <iostream>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "ImagePlane.h"

glm::vec3 color(Sphere& sphere, Ray& ray) {
  surface_hit hit = sphere.intersection(ray); 
  if(hit.did_hit) {
    return 0.5f * (hit.normal + glm::vec3(1, 1, 1));
  };

  return glm::vec3(0, 0, 0);
}

int main() {
  int nx = 600;
  int ny = 300;

  glm::vec3 cameraOrigin(0, 0, 0);
  ImagePlane imagePlane(-2, 2, -1, 1, nx, ny);
  Camera camera(1.0f, cameraOrigin, imagePlane);

  glm::vec3 sphereOrigin(0, 0, -1.0);
  Sphere sphere(sphereOrigin, 0.5);
iliailin
  glm::vec3 sphere2Origin(0, -100.5, -1.0);
  Sphere sphere2(sphere2Origin, 100);

  // Up to down, Right to left
  std::cout << "P3\n" << nx <<  " " << ny << "\n255\n";
  for(int y = 0; y < ny; y++) {
    for(int x = 0; x < nx; x++) {
      Ray ray = camera.shoot(x, y);
      glm::vec3 trace = color(sphere, ray);
      std::cout << int(trace.r * 255.0) << " " << int(trace.g * 255.0) << " " << int(trace.b * 255.0) << "\n";
    }
  }
}