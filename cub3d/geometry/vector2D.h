#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

typedef struct  s_vector2D
{
    double xCoordinate;
    double yCoordinate;
}               t_vector2D;

t_vector2D sum2D(t_vector2D v1, t_vector2D v2);
t_vector2D mult2D(t_vector2D vec, double coef);
double     dot2D(t_vector2D vec1, t_vector2D vec2);
double     lengthSqr2D(t_vector2D vec);
double     length2D(t_vector2D vec);
t_vector2D constructPoint2D(double x, double y);

#endif