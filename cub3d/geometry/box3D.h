#ifndef BOX3D_H
#define BOX3D_H
#include "vector3D.h"
#include "rect3D.h"

typedef struct  s_box3D
{
    t_vector3D center;
    t_vector3D halfSizes;
}               t_box3D;

t_box3D     constructBox(t_vector3D leftDown, t_vector3D rightUp);
BOOL        checkPointInBox(t_box3D box, t_vector3D point);
t_rect3D    constructSide(t_box3D box, int dim, BOOL isMinSide/*какая из граней будет выбрана*/);
#endif