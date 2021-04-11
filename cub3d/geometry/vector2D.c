#include "vector2D.h"
#include <math.h>

t_vector2D    sum2D(t_vector2D v1, t_vector2D v2)
{
    t_vector2D result;

    result.xCoordinate = v1.xCoordinate + v2.xCoordinate;
    result.yCoordinate = v1.yCoordinate + v2.yCoordinate;
    return result;
}

t_vector2D    mult2D(t_vector2D vec, double coef)
{
    t_vector2D result;

    result.xCoordinate = vec.xCoordinate;
    result.yCoordinate = vec.yCoordinate;
    return result;
}

double        dot2D(t_vector2D vec1, t_vector2D vec2)
{
    return vec1.xCoordinate * vec2.xCoordinate + vec1.yCoordinate * vec2.yCoordinate;
}

double        lengthSqr2D(t_vector2D vec)
{
    return dot2D(vec, vec);
}

double        length2D(t_vector2D vec)
{
    return sqrt(lengthSqr2D(vec));
}

t_vector2D constructPoint2D(double x, double y)
{
    t_vector2D point;

    point.xCoordinate = x;
    point.yCoordinate = y;
    return point;
}