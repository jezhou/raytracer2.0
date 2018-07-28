#include "Sphere.h"
#include <glm/geometric.hpp>
#include <glm/exponential.hpp>

// This calculates the discriminant of ray/sphere equation.
// dot(d, d)t ^2 + 2*(d, oc)*t + dot(oc, oc) - radius^2
// This is a general Quadratic Equation where you can figure out a, b, and c.
// Calculating the discriminant is enough to check if we hit the sphere or not.

// Discriminant (Quadratic Equations) = b^2 - 4ac
// Discriminant > 0  => 2 hits (back and front of sphere),
// Discriminant == 1 => 1 hit (side of sphere),
// Discriminant < 0  => no intersections

void Sphere::record_hit(float distance_to_surface, Ray& ray, surface_hit& hit) {
  hit.did_hit = true;
  hit.surface = ray.compute(distance_to_surface);
  hit.normal = glm::normalize(hit.surface - this->center);
}

surface_hit Sphere::intersection(Ray& ray) {
  glm::vec3 oc = ray.getOrigin() - this->center;
  glm::vec3 d = ray.getDirection();
  float r = this->radius;
  float a = dot(d, d);
  float b = dot(oc, d) * 2.0;
  float c = dot(oc, oc) - r * r;
  float discriminant = b * b - 4 * a * c;

  surface_hit hit = {};
  if(discriminant > 0.0) {
    float t1 = (-b - glm::sqrt(discriminant)) / 2.0 * a; // Two intersections, with ray, get the closer one
    float t2 = (-b + glm::sqrt(discriminant)) / 2.0 * a;
    record_hit(t1 < t2 ? t1 : t2, ray, hit);
  } else {
    hit.did_hit = false;
  }

  return hit;
}
