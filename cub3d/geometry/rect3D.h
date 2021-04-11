#ifndef RECT3D_H
#define RECT3D_H
#include "vector2D.h"
#include "vector3D.h"
#include "plane.h"

typedef struct  s_rect3D
{
    t_vector3D center;
    t_vector3D rightDirection;
    t_vector3D upDirection;
    t_vector2D halfSizes;
}               t_rect3D;

t_vector3D  normalRect(t_rect3D rect);
double      distToRect(t_rect3D rect, t_vector3D point);
t_plane     constructPlane(t_rect3D rect);
// point на плоскости rect
t_vector2D  localCoordinate(t_rect3D rect, t_vector3D point);
BOOL        inRect(t_rect3D rect, t_vector2D localCoordinate);
t_vector3D  localToWorld(t_rect3D rect, t_vector2D localCoordinate);
#endif