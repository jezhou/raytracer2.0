#ifndef SPHEREH
#define SPHEREH

// This constant is so we offset the ray. We dont' want the ray to hit the top left corner of the pixel
#define PIXEL_OFFSET 0.5 

#include <glm/vec3.hpp>
#include "Ray.h"

class Sphere {
  public:
  Sphere() {}
  Sphere(glm::vec3& center, float radius) { this->center = center; this->radius = radius; };
  bool intersection(Ray& ray);
  
  private:
  glm::vec3 center;
  float radius;
};

#endif