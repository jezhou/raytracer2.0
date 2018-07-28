#ifndef CAMERAH
#define CAMERAH

#include <glm/vec3.hpp>
#include "Ray.h"
#include "ImagePlane.h"

class Camera {
  public:
  Camera() {}
  Camera(float focalDistance, glm::vec3& origin, ImagePlane& imagePlane) { 
    this->focalDistance = focalDistance;
    this->origin = origin; 
    this->imagePlane = imagePlane;
  };
  Ray shoot(float xCoordinate, float yCoordinate); 
  
  private:
  ImagePlane imagePlane;
  float focalDistance; // essentially how far we are from the pixel plane
  glm::vec3 origin;
};

#endif