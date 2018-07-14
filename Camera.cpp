#include "Camera.h"
#include "Ray.h"

Ray Camera::shoot(float xCoordinate, float yCoordinate) {

  // -focalDistance because we're looking down at the image; this is convention
  glm::vec3 direction(
    xCoordinate + PIXEL_OFFSET,
    yCoordinate + PIXEL_OFFSET,
    -this->focalDistance
  );

  return Ray(this->origin, direction);
}