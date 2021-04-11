#include "vector_int.h"
#include <math.h>

t_vec_int	sum_v_i(t_vec_int v1, t_vec_int v2)
{
	t_vec_int	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_vec_int	mult_v_i(t_vec_int vec, int coef)
{
	t_vec_int	result;

	result.x = vec.x * coef;
	result.y = vec.y * coef;
	return (result);
}

int	dot_v_i(t_vec_int vec1, t_vec_int vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y);
}

int	length_sqr_v_i(t_vec_int vec)
{
	return (dot_v_i(vec, vec));
}

t_vec_int	construct_v_i(int x, int y)
{
	t_vec_int	point;

	point.x = x;
	point.y = y;
	return (point);
}
