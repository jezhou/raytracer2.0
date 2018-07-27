#ifndef CAMERAH
#define CAMERAH

// This constant is so we offset the ray. We dont' want the ray to hit the top left corner of the pixel
#define PIXEL_OFFSET 0.5 

#include <glm/vec3.hpp>
#include "Ray.h"

class Camera {
  public:
  Camera() {}
  Camera(float focalDistance, glm::vec3& origin) { this->focalDistance = focalDistance; this->origin = origin; };
  Ray shoot(float xCoordinate, float yCoordinate); 
  
  private:
  float focalDistance; // essentially how far we are from the pixel plane
  glm::vec3 origin;
};

#endif