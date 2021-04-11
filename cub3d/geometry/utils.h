#ifndef UTILS_H
#define UTILS_H
#include "vector3D.h"
#include "plane.h"
#include "ray3D.h"
#include "box3D.h"

#define EPS 1e-5

BOOL    collision(t_plane plane, t_ray3D ray, t_vector3D* coll);
double  distToBox(t_box3D box, t_vector3D point);

#endif