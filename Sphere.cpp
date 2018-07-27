#include "Sphere.h"
#include <glm/geometric.hpp>
#include <glm/exponential.hpp>

// This calculates the discriminant of ray/sphere equation.
// dot(d, d)t ^2 + 2*(d, oc)*t + dot(oc, oc) - radius^2
// This is a general Quadratic Equation where you can figure out a, b, and c.
// Calculating the discriminant is enough to check if we hit the sphere or not.
// Discriminant > 0 => 2 hits (back and front of sphere),
// Discriminant == 1 => 1 hit (side of sphere),
// Discriminant < 0 => no intersections
bool Sphere::intersection(Ray& ray) {
  glm::vec3 oc = ray.getOrigin() - this->center;
  glm::vec3 d = ray.getDirection();
  float a = dot(d, d);
  float b = dot(d, oc) * 2;
  float c = dot(oc, oc) - pow(radius, 2);
  float discriminant = pow(b, 2) - 4 * a * c;
  return discriminant >= 0.0;
}
