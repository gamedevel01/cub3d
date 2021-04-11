/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:07:39 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/17 16:43:29 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include "vector/vector_dou.h"
# include "vector/vector_int.h"

# define RESOL_WIDTH_MAX 1000000
# define RESOL_HEIGTH_MAX 500000

# define ERROR -1
# define WRONG_RESOL -1
# define WRONG_TEXTURE -2
# define WRONG_COLOR -3
# define KEY_DUPLICATE -4
# define KEY_LOW -5

# define EMPTY_SPACE 0
# define WALL 1
# define ITEM 2

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SCALE 64
# define SPEED 1

# define A 0

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_resolution
{
	int			width;
	int			heigth;
}t_resolution;

typedef	struct	s_texture
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	char		*sprite_path;
}				t_texture;

typedef	struct	s_color
{
	int			red;
	int			blue;
	int			green;

}				t_color;

typedef struct	s_player
{
	double		move_speed;
	double		rot_speed;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_map
{
	char	**map;
	int		count;
	int		max;
}t_map;

typedef	struct s_info
{
	t_resolution	resol;
	t_texture		texture;
	t_color			f_color;
	t_color			c_color;
	t_player		player;
	t_data			data;
	t_map			map;
	void			*mlx;
	void			*win;
}t_info;

void	parser_resolution(char *line, t_resolution *resol);
void	parser_texture(char *line, t_texture *texture);
void	parser_color(char *line, t_info *info);
int		parser(t_info *info);

void	ft_wich_error(int error);
void	ft_print_error(char *text);
void	check_press(int key, t_info *info);
void	check_release(int key, t_info *info);

int		ft_mass_strlen(char **mass);
void	ft_print_all(t_info info); // ДЛЯ ТЕСТОВ
void	set_info(t_info *info); // обнуление инфо

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_square(int pos_x, int pos_y, t_data  img, int color);
#endif
