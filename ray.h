#ifndef RAYH
#define RAYH
#include <glm/vec3.hpp>

class ray {
  public:
  ray() {}
  ray(const glm::vec3& origin, const glm::vec3& end) { this->origin = origin; this->end = end; }
  glm::vec3 getOrigin() const { return origin; }
  glm::vec3 getDirection() const { return end; }
  glm::vec3 compute(const float magnitude) const { return origin + magnitude * (end - origin); } // Ray Equation

  private:
  glm::vec3 origin;
  glm::vec3 end;
};
#endif