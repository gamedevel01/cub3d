#ifndef VECTOR_INT_H
# define VECTOR_INT_H

# include <math.h>

typedef struct s_vec_int
{
	int	x;
	int	y;
}				t_vec_int;

t_vec_int	sum2D(t_vec_int v1, t_vec_int v2);
t_vec_int	mult2D(t_vec_int vec, int coef);
int			dot2D(t_vec_int vec1, t_vec_int vec2);
int			lengthSqr2D(t_vec_int vec);
int			length2D(t_vec_int vec);
t_vec_int	constructPoint2D(int x, int y);

#endif