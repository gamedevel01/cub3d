#ifndef RAY3D_H
#define RAY3D_H
#include "vector3D.h"

typedef struct s_ray3D
{
    t_vector3D origin;
    t_vector3D direction;
}               t_ray3D;

BOOL onRay(t_vector3D point, t_ray3D ray);

#endif