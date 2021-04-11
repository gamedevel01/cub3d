#ifndef VECTOR3D_H
#define VECTOR3D_H
#define BOOL    char
#define TRUE    1
#define FALSE   0
#define ABS(a) ((a) > 0 ? (a) : -(a))

typedef struct s_vector3D
{
    double xCoordinate;
    double yCoordinate;
    double zCoordinate;
}              t_vector3D;

t_vector3D  sum3D(t_vector3D v1, t_vector3D v2);
t_vector3D  diff3D(t_vector3D v1, t_vector3D v2);
t_vector3D  mult3D(t_vector3D vec, double coef);
t_vector3D  crossVectors3D(t_vector3D first, t_vector3D second);
t_vector3D* normalize3D(t_vector3D* vector);
double      dot3D(t_vector3D vec1, t_vector3D vec2);
double      lengthSqr3D(t_vector3D vec);
double      length3D(t_vector3D vec);
double      distance(t_vector3D vec1, t_vector3D vec2);
t_vector3D  constructPoint3D(double x, double y, double z);
#endif