/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:00:48 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/19 19:27:36 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
#include "mlx/mlx.h"
#include "key_macos.h"
#include "cub3d.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define tex_width 64
#define tex_heigth 64
#define mapWidth 24
#define mapHeight 24

t_info info;

int world_map[mapWidth][mapHeight] =
									{
										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
									};

void	draw(t_info *info)
{
	for (int y = 0; y < info->resol.heigth; y++)
	{
		for (int x = 0; x < info->resol.width; x++)
		{
			info->img.data[y * info->resol.width + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == W)
		info->key.w = 0;
	else if (key == A)
		info->key.a = 0;
	else if (key == S)
		info->key.s = 0;
	else if (key == D)
		info->key.d = 0;
	return (0);
}

void	calc(t_info *info)
{
	//floor
	for(int y = 0; y < info->resol.heigth; y++)
	{
		float ray_dir_x0 = info->player.dir_x - info->player.plane_x;
		float ray_dir_y0 = info->player.dir_y - info->player.plane_y;
		float ray_dir_x1 = info->player.dir_x + info->player.plane_x;
		float ray_dir_y1 = info->player.dir_y + info->player.plane_y;
		int p = y - info->resol.heigth / 2;
		float pos_z = 0.5 * info->resol.heigth;
		float row_distance = pos_z / p;
		float floor_step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / info->resol.width;
		float floor_step_y = row_distance * (ray_dir_y1 - ray_dir_y0) / info->resol.width;
		float floor_x = info->player.pos_x + row_distance * ray_dir_x0;
		float floor_y = info->player.pos_y + row_distance * ray_dir_y0;
		for(int x = 0; x < info->resol.width; ++x)
		{
			int cell_x = (int)(floor_x);
			int cell_y = (int)(floor_y);
			int tx = (int)(tex_width * (floor_x - cell_x)) & (tex_width - 1);
			int ty = (int)(tex_heigth * (floor_y - cell_y)) & (tex_heigth - 1);

			floor_x += floor_step_x;
			floor_y += floor_step_y;
			int floorTexture = 3;
			int ceilingTexture = 6;

			int color;
			color = info->texture[floorTexture][tex_width * ty + tx];
			color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
			color = info->texture[ceilingTexture][tex_width * ty + tx];
			color = (color >> 1) & 8355711;
			info->buf[info->resol.heigth - y - 1][x] = color;
		}
	}
	//Wall
	for(int x = 0; x < info->resol.width; x++)
	{
		double cameraX = 2 * x / (double)info->resol.width - 1;
		double rayDirX = info->player.dir_x + info->player.plane_x * cameraX;
		double rayDirY = info->player.dir_y + info->player.plane_y * cameraX;
		
		int mapX = (int)info->player.pos_x;
		int mapY = (int)info->player.pos_y;
		double dist_side_x;
		double sideDistY;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perp_wall_dist;
		int stepX;
		int stepY;
		int hit = 0;
		int side;
		if (rayDirX < 0)
		{
			stepX = -1;
			dist_side_x = (info->player.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			dist_side_x = (mapX + 1.0 - info->player.pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->player.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->player.pos_y) * deltaDistY;
		}

		while (hit == 0)
		{
			if (dist_side_x < sideDistY)
			{
				dist_side_x += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (world_map[mapX][mapY] > 0) hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (mapX - info->player.pos_x + (1 - stepX) / 2) / rayDirX;
		else
			perp_wall_dist = (mapY - info->player.pos_y + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(info->resol.heigth / perp_wall_dist);
		int drawStart = -lineHeight / 2 + info->resol.heigth / 2;
		if(drawStart < 0)
			drawStart = 0;
		int end_draw = lineHeight / 2 + info->resol.heigth / 2;
		if(end_draw >= info->resol.heigth)
			end_draw = info->resol.heigth - 1;
		int texNum = world_map[mapX][mapY] - 1;
		double wallX;
		if (side == 0)
			wallX = info->player.pos_y + perp_wall_dist * rayDirY;
		else
			wallX = info->player.pos_x + perp_wall_dist * rayDirX;
		wallX -= floor(wallX);
		int texX = (int)(wallX * (double)tex_width);
		if (side == 0 && rayDirX > 0)
			texX = tex_width - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = tex_width - texX - 1;
		double step = 1.0 * tex_heigth / lineHeight;
		double texPos = (drawStart - info->resol.heigth / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < end_draw; y++)
		{
			int texY = (int)texPos & (tex_heigth - 1);
			texPos += step;
			int color = info->texture[texNum][tex_heigth * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;

			info->buf[y][x] = color;
		}

		//FLOOR CASTING (vertical version, directly after drawing the vertical wall stripe for the current x)
		double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

		//4 different wall directions possible
		if(side == 0 && rayDirX > 0)
		{
			floorXWall = mapX;
			floorYWall = mapY + wallX;
		}
		else if(side == 0 && rayDirX < 0)
		{
			floorXWall = mapX + 1.0;
			floorYWall = mapY + wallX;
		}
		else if(side == 1 && rayDirY > 0)
		{
			floorXWall = mapX + wallX;
			floorYWall = mapY;
		}
		else
		{
			floorXWall = mapX + wallX;
			floorYWall = mapY + 1.0;
		}

		double distWall, distPlayer, currentDist;

		distWall = perp_wall_dist;
		distPlayer = 0.0;

		if (end_draw < 0) end_draw = info->resol.heigth; //becomes < 0 when the integer overflows

		//draw the floor from end_draw to the bottom of the screen
		for(int y = end_draw + 1; y < info->resol.heigth; y++)
		{
			currentDist = info->resol.heigth / (2.0 * y - info->resol.heigth); //you could make a small lookup table for this instead

			double weight = (currentDist - distPlayer) / (distWall - distPlayer);

			double currentFloorX = weight * floorXWall + (1.0 - weight) * info->player.pos_x;
			double currentFloorY = weight * floorYWall + (1.0 - weight) * info->player.pos_y;

			int floorTexX, floorTexY;
			floorTexX = (int)(currentFloorX * tex_width) % tex_width;
			floorTexY = (int)(currentFloorY * tex_heigth) % tex_heigth;

			int checkerBoardPattern = ((int)(currentFloorX) + (int)(currentFloorY)) % 2;
			int floorTexture;
			if(checkerBoardPattern == 0) floorTexture = 3;
			else floorTexture = 4;

			//floor
			info->buf[y][x] = (info->texture[floorTexture][tex_width * floorTexY + floorTexX] >> 1) & 8355711;
			//ceiling (symmetrical!)
			info->buf[info->resol.heigth - y][x] = info->texture[6][tex_width * floorTexY + floorTexX];
		}
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == W)
	{
		if (!world_map[(int)(info->player.pos_x + info->player.dir_x * info->player.move_speed)][(int)(info->player.pos_y)])
			info->player.pos_x += info->player.dir_x * info->player.move_speed;
		if (!world_map[(int)(info->player.pos_x)][(int)(info->player.pos_y + info->player.dir_y * info->player.move_speed)])
			info->player.pos_y += info->player.dir_y * info->player.move_speed;
		info->key.w = 1;
	}
	//move backwards if no wall behind you
	if (key == S)
	{
		if (!world_map[(int)(info->player.pos_x - info->player.dir_x * info->player.move_speed)][(int)(info->player.pos_y)])
			info->player.pos_x -= info->player.dir_x * info->player.move_speed;
		if (!world_map[(int)(info->player.pos_x)][(int)(info->player.pos_y - info->player.dir_y * info->player.move_speed)])
			info->player.pos_y -= info->player.dir_y * info->player.move_speed;
		info->key.s = 1;
	}
	//rotate to the right
	if (key == D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->player.dir_x;
		info->player.dir_x = info->player.dir_x * cos(-info->player.rot_speed) - info->player.dir_y * sin(-info->player.rot_speed);
		info->player.dir_y = oldDirX * sin(-info->player.rot_speed) + info->player.dir_y * cos(-info->player.rot_speed);
		double oldPlaneX = info->player.plane_x;
		info->player.plane_x = info->player.plane_x * cos(-info->player.rot_speed) - info->player.plane_y * sin(-info->player.rot_speed);
		info->player.plane_y = oldPlaneX * sin(-info->player.rot_speed) + info->player.plane_y * cos(-info->player.rot_speed);
		info->key.d = 1;
	}
	if (key == A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->player.dir_x;
		info->player.dir_x = info->player.dir_x * cos(info->player.rot_speed) - info->player.dir_y * sin(info->player.rot_speed);
		info->player.dir_y = oldDirX * sin(info->player.rot_speed) + info->player.dir_y * cos(info->player.rot_speed);
		double oldPlaneX = info->player.plane_x;
		info->player.plane_x = info->player.plane_x * cos(info->player.rot_speed) - info->player.plane_y * sin(info->player.rot_speed);
		info->player.plane_y = oldPlaneX * sin(info->player.rot_speed) + info->player.plane_y * cos(info->player.rot_speed);
		info->key.a = 1;
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_heigth);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_heigth; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}


int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	info.player.pos_x = 22.0;
	info.player.pos_y = 11.5;
	info.player.dir_x = -1.0;
	info.player.dir_y = 0.0;
	info.player.plane_x = 0.0;
	info.player.plane_y = 0.66;
	info.resol.heigth = 640;
	info.resol.width = 480;
	/*
	ТУТ ДОЛЖЕН БЫТЬ ПАРСЕР
	*/
	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (tex_heigth * tex_width))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < tex_heigth * tex_width; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	load_texture(&info);

	info.player.move_speed = 0.05;
	info.player.rot_speed = 0.05;
	
	info.win = mlx_new_window(info.mlx, info.resol.width, info.resol.heigth, "mlx");

	info.img.img = mlx_new_image(info.mlx, info.resol.width, info.resol.heigth);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_hook(info.win, 3, 0, &key_release, &info);

	mlx_loop(info.mlx);
}
