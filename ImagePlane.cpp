#include "ImagePlane.h"

// This transforms a coordinate by the x and y pixel into
// coordinates in world space, which is needed to help
// generate rays in the camera.

glm::vec2 ImagePlane::toWorldSpace(int xPixel, int yPixel)
{
  float u = this->left + this->width() * (xPixel + PIXEL_OFFSET) / this->rasterWidth;
  float v = this->bottom + this->height() * (yPixel + PIXEL_OFFSET) / this->rasterHeight;
  return glm::vec2(u, v);
}
