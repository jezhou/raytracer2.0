#ifndef IMAGEPLANEH
#define IMAGEPLANEH

// This constant is so we offset the ray. We dont' want the ray to hit the top left corner of the pixel
#define PIXEL_OFFSET 0.5 
#include <glm/vec2.hpp>

// It's kind of hard to explain what this class is, but it essentially holds the image size
// and the size of the space the camera is shooting at in world space.
// It also includes methods that help transition an <x,y> pixel coordinate into worldspace.

class ImagePlane
{
  public:
    ImagePlane() {}
    ImagePlane(float left, float right, float bottom, float top, float rasterWidth, float rasterHeight) : 
      left(left), right(right), bottom(bottom), top(top), rasterWidth(rasterWidth), rasterHeight(rasterHeight) {}
    float width() { return this->right - this->left; }
    float height() { return this->top - this->bottom; }
    glm::vec2 toWorldSpace(int xPixel, int yPixel);

  private:
    // Bounds of the image plane
    float left;
    float right;
    float bottom;
    float top;

    // Size of the image in pixels, width x height
    float rasterWidth;
    float rasterHeight;
};

#endif