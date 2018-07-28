#ifndef RAYH
#define RAYH
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

class Ray {
  public:
  Ray() {}
  Ray(const glm::vec3& origin, const glm::vec3& direction) { this->origin = origin; this->direction = glm::normalize(direction); }
  glm::vec3 getOrigin() const { return origin; }
  glm::vec3 getDirection() const { return direction; }
  glm::vec3 compute(const float magnitude) const { return origin + magnitude * direction; } // Ray Equation

  private:
  glm::vec3 origin;
  glm::vec3 direction;
};
#endif