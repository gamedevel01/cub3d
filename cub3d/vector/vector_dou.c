#include "vector_dou.h"
#include <math.h>

t_vec_d	sum2d(t_vec_d v1, t_vec_d v2)
{
	t_vec_d	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_vec_d	mult2d(t_vec_d vec, double coef)
{
	t_vec_d	result;

	result.x = vec.x * coef;
	result.y = vec.y * coef;
	return (result);
}

double	dot2d(t_vec_d vec1, t_vec_d vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y);
}

double	length_sqr2d(t_vec_d vec)
{
	return (dot2d(vec, vec));
}

t_vec_d	construct2d(double x, double y)
{
	t_vec_d	point;

	point.x = x;
	point.y = y;
	return (point);
}
