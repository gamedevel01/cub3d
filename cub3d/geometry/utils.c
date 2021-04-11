#include "utils.h"

BOOL    collision(t_plane plane, t_ray3D ray, t_vector3D* coll)
{
    /*
        (plane.normal, ray.origin + t * ray.direction) = plane.bias
        t * (plane.normal, ray.direction) = plane.bias - (plane.normal, ray.origin)
    */
    double normalDirScalar;
    double normalOriginScalar;

    normalDirScalar     = dot3D(plane.normal, ray.direction);
    normalOriginScalar  = dot3D(plane.normal, ray.origin);

    double coord = plane.bias - normalOriginScalar;
    if (ABS(coord) < EPS)
    {
        if (coll)
            *coll = ray.origin;
        return TRUE;
    }
    if (ABS(normalDirScalar) < EPS)
    {
        return FALSE;
    }
    coord /= normalDirScalar;
    if (coord < 0.)
        return FALSE;
    if (coll)
        *coll = sum3D(ray.origin, mult3D(ray.direction, coord));
    return TRUE;
}

double  distToBox(t_box3D box, t_vector3D point)
{
    double dist = -1;
    for (int dim = 0; dim < 3; ++dim)
    {
        for (BOOL isMinSide = FALSE; isMinSide <= TRUE; ++isMinSide)
        {
            t_rect3D side;

            side = constructSide(box, dim, isMinSide);
            double distToSide;
            
            distToSide = distToRect(side, point);
            if (dist < 0. || dist < distToSide)
                dist = distToSide;
        }
    }
    return dist;
}