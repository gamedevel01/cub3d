/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:07:39 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/22 17:41:46 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "liba/libft.h"
# include "mlx.h"
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

typedef struct	  s_data {
    char      	  *addr;
    int      	  bits_per_pixel;
    int       	  line_length;
    int       	  endian;
}             	  t_data;

typedef struct		s_resol
{
	int				width;
	int				heigth;
}					t_resol;

typedef	struct		s_texture_info
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*sprite_path;
}					t_texture_info;

typedef	struct		s_color
{
	int				red;
	int				blue;
	int				green;

}					t_color;

typedef struct		s_player
{
	int				side;
	int				hit;
	int				map_x;
	int				map_y;
	double			pos_x;
	double			pos_y;
	double			camera;
	double			move_speed;
	double			rot_speed;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_x;
	double			delta_y;
}					t_player;

typedef struct		s_ray
{
	double			perp_for_wall;
	float			ray_dir_x_0;
	float			ray_dir_x_1;
	float			ray_dir_y_0;
	float			ray_dir_y_1;
	float			cur_pos_y;
	float			pos_z;
	float			row_distance;
	float			floor_step_x;
	float			floor_step_y;
	float			step_x;
	float			step_y;
	float			floor_x;
	float			floor_y;
}					t_ray;

typedef struct		s_key
{
	int				w;
	int				a;
	int				s;
	int				d;	
}					t_key;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_heigth;
}					t_img;



typedef struct		s_info
{
	t_resol			resol;
	t_texture_info	texture_info;
	t_color			f_color;
	t_color			c_color;
	t_player		player;
	t_data			data;
	t_img			img;
	t_ray			ray;
	t_key			key;
	char			**map;
	void			*mlx;
	void			*win;
	int				**buf; // для текстур временно
	int				**texture;
}					t_info;

void	parser_resolution(char *line, t_resol *resol);
void	parser_texture(char *line, t_texture_info *texture_info);
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
