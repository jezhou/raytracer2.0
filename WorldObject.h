#ifndef WORLDOBJECTH
#define WORLDOBJECTH

#include <glm/vec3.hpp>
#include "Ray.h"

struct surface_hit {
  bool did_hit;
  glm::vec3 surface; // Point where on the surface the object was hit, in world space
  glm::vec3 normal;  // The normal from where the surface was hit, normalized
};

class WorldObject {
  public:
  virtual surface_hit intersection(Ray& ray) { 
    surface_hit hit;
    hit.did_hit = false;
    return hit;
  };
};

#endif