#include "plane.h"

t_plane     construct(t_vector3D first, t_vector3D second, t_vector3D third)
{
    t_vector3D normal;
    
    normal = crossVectors3D(diff3D(first, second), diff3D(first, third));
    normalize3D(&normal);
    t_plane plane;

    plane.normal = normal;
    plane.bias = dot3D(normal, first);
}

double      distToPlane(t_plane plane, t_vector3D point)
{
    return plane.bias - dot3D(plane.normal, point);
}

t_vector3D  projectToPlane(t_plane plane, t_vector3D point)
{
    return sum3D(point, mult3D(plane.normal, distToPlane(plane, point)));
}