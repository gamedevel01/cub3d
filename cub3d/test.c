/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:39 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/22 17:44:43 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define tex_width 64
#define tex_height 64

int		is_step(t_info *info)
{
	if (info->ray.ray_dir_x_0 < 0)
		{
			info->ray.step_x = -1;
			info->player.side_dist_y = (info->player.pos_x - info->player.map_x) * info->player.delta_x;
		}
		else
		{
			info->ray.step_x = 1;
			info->player.side_dist_x = (info->player.map_x + 1.0 - info->player.pos_x) * info->player.delta_x;
		}
		if (info->ray.ray_dir_y_0 < 0)
		{
			info->ray.step_y = -1;
			info->player.side_dist_y = (info->player.pos_y - info->player.map_y) *info->player.delta_y;
		}
		else
		{
			info->ray.step_y = 1;
			info->player.side_dist_y = (info->player.map_y + 1.0 - info->player.pos_y) * info->player.delta_y;
		}
	return (0);
}

void		ft_math(t_info *info)
{
	int y;
	int x;
	int	tempo_x;
	int tempo_y;

	y = 0;
//FLOOR CASTING
	while (y < info->resol.heigth)
	{

		info->ray.ray_dir_x_0 = info->player.dir_x - info->player.plane_x;
		info->ray.ray_dir_x_1 = info->player.dir_x + info->player.plane_x;
		info->ray.ray_dir_y_0 = info->player.dir_y - info->player.plane_y;
		info->ray.ray_dir_y_1 = info->player.dir_y + info->player.plane_y;

		info->ray.pos_z = info->resol.heigth / 2;
		info->ray.cur_pos_y = y - info->resol.heigth;
		info->ray.row_distance = info->ray.pos_z / info->ray.cur_pos_y;
	
		info->ray.floor_step_x = info->ray.row_distance * (info->ray.ray_dir_x_1 - info->ray.ray_dir_x_0) / info->resol.width;
		info->ray.floor_step_y = info->ray.row_distance * (info->ray.ray_dir_y_1 - info->ray.ray_dir_y_0) / info->resol.width;

		info->ray.floor_x = info->player.pos_x + info->ray.row_distance * info->ray.ray_dir_x_0;
		info->ray.floor_y = info->player.pos_y + info->ray.row_distance * info->ray.ray_dir_y_0;
		x = 0;
		while (x < info->resol.width)
		{
			tempo_x = (int)(tex_width * (info->ray.floor_x - (int)info->ray.floor_x)) & (tex_width - 1);
			tempo_y = (int)(tex_height * (info->ray.floor_y - (int)info->ray.floor_y)) & (tex_height - 1);

			info->ray.floor_x += info->ray.floor_step_x;
			info->ray.floor_y += info->ray.floor_step_y;
// ТЕКСТУРА
			int floorTexture = 3;
			int ceilingTexture = 6;

			int color;

			// floor
			color = info->texture[floorTexture][tex_width * tempo_x + tempo_y];
			color = (color >> 1) & 8355711; // make a bit darker

			info->buf[y][x] = color;

			//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			color = info->texture[ceilingTexture][tex_width * tempo_x + tempo_y];
			color = (color >> 1) & 8355711; // make a bit darker

			info->buf[info->resol.heigth - y - 1][x] = color;
			
			while (info->player.hit == 0)
			{
				if (info->player.side_dist_x < info->player.side_dist_y)
				{
					info->player.side_dist_x += info->player.delta_x;
					info->player.map_x += info->ray.step_x;
					info->player.side = 0;
				}
				else
				{
					info->player.side_dist_y += info->player.delta_y;
					info->player.map_y += info->ray.step_y;
					info->player.side = 1;
				}
				if (info->map[info->player.map_x][info->player.map_y] > 0)
					info->player.hit = 1;
				if (info->player.side == 0)
					info->ray.perp_for_wall = (info->player.map_x - 
					info->player.pos_x + (1 - info->ray.step_x) / 2) / info->ray.ray_dir_x_0;
				else
					info->ray.perp_for_wall = (info->player.map_y - 
					info->player.pos_y + (1 - info->ray.step_y) / 2) / info->ray.ray_dir_y_0;
			}
			
//КОНЕЦ
			x += 1;
		}
//конец floor casting
//Начало WALL CASTING
		y += 1;
		x = 0;
		while (x < info->resol.width)
		{
			info->player.camera = 2 * x / (double)info->resol.width - 1;
			info->ray.ray_dir_x_0 = info->player.dir_x + info->player.plane_x * info->player.camera;
			info->ray.ray_dir_y_0 = info->player.dir_y + info->player.plane_y * info->player.camera; 

			info->player.map_x = (int)info->player.pos_x;
			info->player.map_y = (int)info->player.pos_y;
			info->player.delta_x = abs(1 / info->ray.ray_dir_x_0);
			info->player.delta_y = abs(1 / info->ray.ray_dir_y_0);
			
			info->player.hit = 0;
			
			x += 1;
		}
		
	}
	
}