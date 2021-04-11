#ifndef VECTOR_DOU_H
# define VECTOR_DOU_H

# include <math.h>

typedef struct s_vec_d
{
	double		x;
	double		y;
}				t_vec_d;

t_vec_d	sum_v_d(t_vec_d v1, t_vec_d v2);
t_vec_d	mult_v_d(t_vec_d vec, double coef);
double	dot_v_d(t_vec_d vec1, t_vec_d vec2);
double	length_sqr_v_d(t_vec_d vec);
double	length_v_d(t_vec_d vec);
t_vec_d	construct_v_d(double x, double y);

#endif