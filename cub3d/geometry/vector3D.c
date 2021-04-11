#include "vector3D.h"
#include <math.h>

const double Eps = 0.000001;

t_vector3D    sum3D(t_vector3D v1, t_vector3D v2)
{
    t_vector3D result;

    result.xCoordinate = v1.xCoordinate + v2.xCoordinate;
    result.yCoordinate = v1.yCoordinate + v2.yCoordinate;
    result.zCoordinate = v1.zCoordinate + v2.zCoordinate;
    return result;
}

t_vector3D diff3D(t_vector3D v1, t_vector3D v2)
{
    return sum3D(v1, mult3D(v2, -1.));    
}


t_vector3D    mult3D(t_vector3D vec, double coef)
{
    t_vector3D result;

    result.xCoordinate = vec.xCoordinate * coef;
    result.yCoordinate = vec.yCoordinate * coef;
    result.zCoordinate = vec.zCoordinate * coef;
    return result;
}

t_vector3D      crossVectors3D(t_vector3D first, t_vector3D second)
{
    t_vector3D result;

    result.xCoordinate = first.yCoordinate * second.zCoordinate - 
                         first.zCoordinate * second.yCoordinate;
    result.yCoordinate = first.zCoordinate * second.xCoordinate - 
                         first.xCoordinate * second.zCoordinate;
    result.zCoordinate = first.xCoordinate * second.yCoordinate - 
                         first.yCoordinate * second.xCoordinate;
    return result;
}

t_vector3D*     normalize3D(t_vector3D* vector)
{
    if (!vector) return vector;
    double lengthVector;

    lengthVector = length3D(*vector);
    if (lengthVector < Eps)
        return vector;
    *vector = mult3D(*vector, 1. / lengthVector);
    return vector;
}

double          dot3D(t_vector3D vec1, t_vector3D vec2)
{
    return vec1.xCoordinate * vec2.xCoordinate + 
           vec1.yCoordinate * vec2.yCoordinate +
           vec1.zCoordinate * vec2.zCoordinate;
}

double          lengthSqr3D(t_vector3D vec)
{
    return dot3D(vec, vec);
}

double          length3D(t_vector3D vec)
{
    return sqrt(lengthSqr3D(vec));
}

double          distance(t_vector3D vec1, t_vector3D vec2)
{
    return length3D(diff3D(vec1, vec2));
}

t_vector3D      constructPoint3D(double x, double y, double z)
{
    t_vector3D vector;

    vector.xCoordinate = x;
    vector.yCoordinate = y;
    vector.zCoordinate = z;
    return vector;
}
