#include "Camera.h"
#include "Ray.h"
#include <iostream>

Ray Camera::shoot(float xCoordinate, float yCoordinate) {
  glm::vec2 worldSpaceCoordinates = imagePlane.toWorldSpace(xCoordinate, yCoordinate);
  
  glm::vec3 direction(
    worldSpaceCoordinates.x,
    worldSpaceCoordinates.y,
    -this->focalDistance          // -focalDistance because we're looking down at the image; this is convention
  );

  return Ray(this->origin, direction);
}