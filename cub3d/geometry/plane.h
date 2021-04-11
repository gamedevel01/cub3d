#ifndef PLANE_H
#define PLANE_H
#include "vector3D.h"

typedef struct  s_plane
{
    // point on plane if dot(point, normal) == bias
    t_vector3D normal;
    double bias;
}               t_plane;

t_plane     construct(t_vector3D first, t_vector3D second, t_vector3D third);
// расстояние до плоскости, если двигаться в направлении нормали
double      distToPlane(t_plane plane, t_vector3D point);
t_vector3D  projectToPlane(t_plane plane, t_vector3D point);

#endif