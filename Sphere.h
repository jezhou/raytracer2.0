#ifndef SPHEREH
#define SPHEREH

// This constant is so we offset the ray. We dont' want the ray to hit the top left corner of the pixel
#define PIXEL_OFFSET 0.5 

#include <glm/vec3.hpp>
#include "SceneObject.h"

class Sphere : public SceneObject {
  public:
  Sphere() {}
  Sphere(glm::vec3& center, float radius) : center(center), radius(radius) {};
  surface_hit intersection(Ray& ray);
  
  private:
  glm::vec3 center;
  float radius;
  void record_hit(float distance_to_surface, Ray& ray, surface_hit& hit); // Note: This mutates the hit object.
};

#endif