#include "ray3D.h"

#define EPS 1e-5

BOOL onRay(t_vector3D point, t_ray3D ray)
{
    t_vector3D dirToPoint = diff3D(point, ray.origin);
    double scalar = dot3D(dirToPoint, ray.direction);
    if (scalar < 0.)
        return FALSE;
    if (length3D(dirToPoint) * length3D(ray.direction) < (scalar + EPS))
        return TRUE;
    return FALSE;
}