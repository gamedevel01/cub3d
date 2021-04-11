// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mlx.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/03/10 11:00:48 by bzelda            #+#    #+#             */
// /*   Updated: 2021/03/17 19:10:43 by bzelda           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// // #include "cub3d.h"
// #include "mlx/mlx.h"
// #include "key_macos.h"
// #include <math.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #define X_EVENT_KEY_PRESS	2
// #define X_EVENT_KEY_EXIT	17
// #define texWidth 64
// #define texHeight 64
// #define mapWidth 24
// #define mapHeight 24
// #define width 680
// #define height 400

// typedef struct	s_img
// {
// 	void		*img;
// 	int			*data;
// 	int			size_l;
// 	int			bpp;
// 	int			endian;
// 	int			img_width;
// 	int			img_height;
// }				t_img;

// typedef struct s_key
// {
// 	int			w;
// 	int			a;
// 	int			s;
// 	int			d;	
// }				t_key;

// typedef struct	s_player
// {
// 	double		pos_x;
// 	double		pos_y;
// 	double		dir_x;
// 	double		dir_y;
// 	double		plane_x;
// 	double		plane_y;
// 	double		move_speed;
// 	double		rot_speed;
// }				t_player;

// typedef struct	s_info
// {
// 	void		*mlx;
// 	void		*win;
// 	int			buf[height][width];
// 	int			**texture;
// 	t_player	player;
// 	t_img		img;
// 	t_key		key;
// }				t_info;

// int	worldMap[mapWidth][mapHeight] =
// 									{
// 										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
// 										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
// 										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
// 										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
// 										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
// 										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
// 										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
// 										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
// 										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
// 										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
// 										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
// 										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
// 										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
// 										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
// 										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
// 										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
// 										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
// 										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
// 										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
// 										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
// 										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
// 										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
// 										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
// 										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
// 									};

// void	draw(t_info *info)
// {
// 	for (int y = 0; y < height; y++)
// 	{
// 		for (int x = 0; x < width; x++)
// 		{
// 			info->img.data[y * width + x] = info->buf[y][x];
// 		}
// 	}
// 	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
// }

// int		key_release(int key, t_info *info)
// {
// 	if (key == K_ESC)
// 		exit(0);
// 	else if (key == W)
// 		info->key.w = 0;
// 	else if (key == A)
// 		info->key.a = 0;
// 	else if (key == S)
// 		info->key.s = 0;
// 	else if (key == D)
// 		info->key.d = 0;
// 	return (0);
// }

// void	calc(t_info *info)
// {
// 	//FLOOR CASTING
// 	for(int y = 0; y < height; y++)
// 	{
// 		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
// 		float ray_dir_x0 = info->player.dir_x - info->player.plane_x;
// 		float ray_dir_y0 = info->player.dir_y - info->player.plane_y;
// 		float ray_dir_x1 = info->player.dir_x + info->player.plane_x;
// 		float ray_dir_y1 = info->player.dir_y + info->player.plane_y;

// 		// Current y position compared to the center of the screen (the horizon)
// 		int p = y - height / 2;

// 		// Vertical position of the camera.
// 		float pos_z = 0.5 * height;

// 		// Horizontal distance from the camera to the floor for the current row.
// 		// 0.5 is the z position exactly in the middle between floor and ceiling.
// 		float row_distance = pos_z / p;

// 		// calculate the real world step vector we have to add for each x (parallel to camera plane)
// 		// adding step by step avoids multiplications with a weight in the inner loop
// 		float floor_step_x = row_distance * (ray_dir_x1 - ray_dir_x0) / width;
// 		float floor_step_y = row_distance * (ray_dir_y1 - ray_dir_y0) / width;

// 		// real world coordinates of the leftmost column. This will be updated as we step to the right.
// 		float floor_x = info->player.pos_x + row_distance * ray_dir_x0;
// 		float floor_y = info->player.pos_y + row_distance * ray_dir_y0;

// 		for(int x = 0; x < width; ++x)
// 		{
// 			// the cell coord is simply got from the integer parts of floorX and floorY
// 			int cell_x = (int)(floor_x);
// 			int cell_y = (int)(floor_y);

// 			// get the texture coordinate from the fractional part
// 			int tx = (int)(texWidth * (floor_x - cell_x)) & (texWidth - 1);
// 			int ty = (int)(texHeight * (floor_y - cell_y)) & (texHeight - 1);

// 			floor_x += floor_step_x;
// 			floor_y += floor_step_y;

// 			// choose texture and draw the pixel
// 			int floorTexture = 3;
// 			int ceilingTexture = 6;

// 			int color;

// 			// floor
// 			color = info->texture[floorTexture][texWidth * ty + tx];
// 			color = (color >> 1) & 8355711; // make a bit darker

// 			info->buf[y][x] = color;

// 			//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
// 			color = info->texture[ceilingTexture][texWidth * ty + tx];
// 			color = (color >> 1) & 8355711; // make a bit darker

// 			info->buf[height - y - 1][x] = color;
// 		}
// 	}
// 	//WALL CASTING
// 	for(int x = 0; x < width; x++)
// 	{
// 		double cameraX = 2 * x / (double)width - 1;
// 		double rayDirX = info->player.dir_x + info->player.plane_x * cameraX;
// 		double rayDirY = info->player.dir_y + info->player.plane_y * cameraX;
		
// 		int mapX = (int)info->player.pos_x;
// 		int mapY = (int)info->player.pos_y;

// 		//length of ray from current position to next x or y-side
// 		double dist_side_x;
// 		double sideDistY;
		
// 		 //length of ray from one x or y-side to next x or y-side
// 		double deltaDistX = fabs(1 / rayDirX);
// 		double deltaDistY = fabs(1 / rayDirY);
// 		double perpWallDist;
		
// 		//what direction to step in x or y-direction (either +1 or -1)
// 		int stepX;
// 		int stepY;
		
// 		int hit = 0; //was there a wall hit?
// 		int side; //was a NS or a EW wall hit?

// 		if (rayDirX < 0)
// 		{
// 			stepX = -1;
// 			dist_side_x = (info->player.pos_x - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			dist_side_x = (mapX + 1.0 - info->player.pos_x) * deltaDistX;
// 		}
// 		if (rayDirY < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (info->player.pos_y - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - info->player.pos_y) * deltaDistY;
// 		}

// 		while (hit == 0)
// 		{
// 			//jump to next map square, OR in x-direction, OR in y-direction
// 			if (dist_side_x < sideDistY)
// 			{
// 				dist_side_x += deltaDistX;
// 				mapX += stepX;
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDistY += deltaDistY;
// 				mapY += stepY;
// 				side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			if (worldMap[mapX][mapY] > 0) hit = 1;
// 		}
// 		if (side == 0)
// 			perpWallDist = (mapX - info->player.pos_x + (1 - stepX) / 2) / rayDirX;
// 		else
// 			perpWallDist = (mapY - info->player.pos_y + (1 - stepY) / 2) / rayDirY;

// 		//Calculate height of line to draw on screen
// 		int lineHeight = (int)(height / perpWallDist);

// 		//calculate lowest and highest pixel to fill in current stripe
// 		int drawStart = -lineHeight / 2 + height / 2;
// 		if(drawStart < 0)
// 			drawStart = 0;
// 		int drawEnd = lineHeight / 2 + height / 2;
// 		if(drawEnd >= height)
// 			drawEnd = height - 1;

// 		// texturing calculations
// 		int texNum = worldMap[mapX][mapY] - 1;

// 		// calculate value of wallX
// 		double wallX;
// 		if (side == 0)
// 			wallX = info->player.pos_y + perpWallDist * rayDirY;
// 		else
// 			wallX = info->player.pos_x + perpWallDist * rayDirX;
// 		wallX -= floor(wallX);

// 		// x coordinate on the texture
// 		int texX = (int)(wallX * (double)texWidth);
// 		if (side == 0 && rayDirX > 0)
// 			texX = texWidth - texX - 1;
// 		if (side == 1 && rayDirY < 0)
// 			texX = texWidth - texX - 1;

// 		// How much to increase the texture coordinate perscreen pixel
// 		double step = 1.0 * texHeight / lineHeight;

// 		// Starting texture coordinate
// 		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;

// 		for (int y = drawStart; y < drawEnd; y++)
// 		{
// 			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
// 			int texY = (int)texPos & (texHeight - 1);
// 			texPos += step;

// 			int color = info->texture[texNum][texHeight * texY + texX];

// 			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 			if (side == 1)
// 				color = (color >> 1) & 8355711;

// 			info->buf[y][x] = color;
// 		}

// 		//FLOOR CASTING (vertical version, directly after drawing the vertical wall stripe for the current x)
// 		double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

// 		//4 different wall directions possible
// 		if(side == 0 && rayDirX > 0)
// 		{
// 			floorXWall = mapX;
// 			floorYWall = mapY + wallX;
// 		}
// 		else if(side == 0 && rayDirX < 0)
// 		{
// 			floorXWall = mapX + 1.0;
// 			floorYWall = mapY + wallX;
// 		}
// 		else if(side == 1 && rayDirY > 0)
// 		{
// 			floorXWall = mapX + wallX;
// 			floorYWall = mapY;
// 		}
// 		else
// 		{
// 			floorXWall = mapX + wallX;
// 			floorYWall = mapY + 1.0;
// 		}

// 		double distWall, distPlayer, currentDist;

// 		distWall = perpWallDist;
// 		distPlayer = 0.0;

// 		if (drawEnd < 0) drawEnd = height; //becomes < 0 when the integer overflows

// 		//draw the floor from drawEnd to the bottom of the screen
// 		for(int y = drawEnd + 1; y < height; y++)
// 		{
// 			currentDist = height / (2.0 * y - height); //you could make a small lookup table for this instead

// 			double weight = (currentDist - distPlayer) / (distWall - distPlayer);

// 			double currentFloorX = weight * floorXWall + (1.0 - weight) * info->player.pos_x;
// 			double currentFloorY = weight * floorYWall + (1.0 - weight) * info->player.pos_y;

// 			int floorTexX, floorTexY;
// 			floorTexX = (int)(currentFloorX * texWidth) % texWidth;
// 			floorTexY = (int)(currentFloorY * texHeight) % texHeight;

// 			int checkerBoardPattern = ((int)(currentFloorX) + (int)(currentFloorY)) % 2;
// 			int floorTexture;
// 			if(checkerBoardPattern == 0) floorTexture = 3;
// 			else floorTexture = 4;

// 			//floor
// 			info->buf[y][x] = (info->texture[floorTexture][texWidth * floorTexY + floorTexX] >> 1) & 8355711;
// 			//ceiling (symmetrical!)
// 			info->buf[height - y][x] = info->texture[6][texWidth * floorTexY + floorTexX];
// 		}
// 	}
// }

// int	main_loop(t_info *info)
// {
// 	calc(info);
// 	draw(info);
// 	return (0);
// }
// /*
// int		key_press(int key, t_info *info)
// {
// 	if (key == K_ESC)
// 		exit(0);
// 	else if (key == K_W)
// 		info->key.w = 1;
// 	else if (key == K_A)
// 		info->key.a = 1;
// 	else if (key == K_S)
// 		info->key.s = 1;
// 	else if (key == K_D)
// 		info->key.d = 1;
// 	return (0);
// }
// */
// int	key_press(int key, t_info *info)
// {
// 	if (key == W)
// 	{
// 		if (!worldMap[(int)(info->player.pos_x + info->player.dir_x * info->player.move_speed)][(int)(info->player.pos_y)])
// 			info->player.pos_x += info->player.dir_x * info->player.move_speed;
// 		if (!worldMap[(int)(info->player.pos_x)][(int)(info->player.pos_y + info->player.dir_y * info->player.move_speed)])
// 			info->player.pos_y += info->player.dir_y * info->player.move_speed;
// 		info->key.w = 1;
// 	}
// 	//move backwards if no wall behind you
// 	if (key == S)
// 	{
// 		if (!worldMap[(int)(info->player.pos_x - info->player.dir_x * info->player.move_speed)][(int)(info->player.pos_y)])
// 			info->player.pos_x -= info->player.dir_x * info->player.move_speed;
// 		if (!worldMap[(int)(info->player.pos_x)][(int)(info->player.pos_y - info->player.dir_y * info->player.move_speed)])
// 			info->player.pos_y -= info->player.dir_y * info->player.move_speed;
// 		info->key.s = 1;
// 	}
// 	//rotate to the right
// 	if (key == D)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = info->player.dir_x;
// 		info->player.dir_x = info->player.dir_x * cos(-info->player.rot_speed) - info->player.dir_y * sin(-info->player.rot_speed);
// 		info->player.dir_y = oldDirX * sin(-info->player.rot_speed) + info->player.dir_y * cos(-info->player.rot_speed);
// 		double oldPlaneX = info->player.plane_x;
// 		info->player.plane_x = info->player.plane_x * cos(-info->player.rot_speed) - info->player.plane_y * sin(-info->player.rot_speed);
// 		info->player.plane_y = oldPlaneX * sin(-info->player.rot_speed) + info->player.plane_y * cos(-info->player.rot_speed);
// 		info->key.d = 1;
// 	}
// 	if (key == A)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = info->player.dir_x;
// 		info->player.dir_x = info->player.dir_x * cos(info->player.rot_speed) - info->player.dir_y * sin(info->player.rot_speed);
// 		info->player.dir_y = oldDirX * sin(info->player.rot_speed) + info->player.dir_y * cos(info->player.rot_speed);
// 		double oldPlaneX = info->player.plane_x;
// 		info->player.plane_x = info->player.plane_x * cos(info->player.rot_speed) - info->player.plane_y * sin(info->player.rot_speed);
// 		info->player.plane_y = oldPlaneX * sin(info->player.rot_speed) + info->player.plane_y * cos(info->player.rot_speed);
// 		info->key.a = 1;
// 	}
// 	if (key == K_ESC)
// 		exit(0);
// 	return (0);
// }

// void	load_image(t_info *info, int *texture, char *path, t_img *img)
// {
// 	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
// 	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
// 	for (int y = 0; y < img->img_height; y++)
// 	{
// 		for (int x = 0; x < img->img_width; x++)
// 		{
// 			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
// 		}
// 	}
// 	mlx_destroy_image(info->mlx, img->img);
// }

// void	load_texture(t_info *info)
// {
// 	t_img	img;

// 	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
// 	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
// 	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
// 	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
// 	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
// 	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
// 	load_image(info, info->texture[6], "textures/wood.xpm", &img);
// 	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
// }


// int	main(void)
// {
// 	t_info info;
// 	info.mlx = mlx_init();

// 	info.player.pos_x = 22.0;
// 	info.player.pos_y = 11.5;
// 	info.player.dir_x = -1.0;
// 	info.player.dir_y = 0.0;
// 	info.player.plane_x = 0.0;
// 	info.player.plane_y = 0.66;

// 	for (int i = 0; i < height; i++)
// 	{
// 		for (int j = 0; j < width; j++)
// 		{
// 			info.buf[i][j] = 0;
// 		}
// 	}

// 	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
// 		return (-1);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
// 			return (-1);
// 	}
// 	for (int i = 0; i < 8; i++)
// 	{
// 		for (int j = 0; j < texHeight * texWidth; j++)
// 		{
// 			info.texture[i][j] = 0;
// 		}
// 	}

// 	load_texture(&info);

// 	info.player.move_speed = 0.05;
// 	info.player.rot_speed = 0.05;
	
// 	info.win = mlx_new_window(info.mlx, width, height, "mlx");

// 	info.img.img = mlx_new_image(info.mlx, width, height);
// 	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

// 	mlx_loop_hook(info.mlx, &main_loop, &info);
// 	mlx_hook(info.win, 2, 0, &key_press, &info);
// 	mlx_hook(info.win, 3, 0, &key_release, &info);

// 	mlx_loop(info.mlx);
// }

// // 	info.mlx = mlx_init();
// // 	info.win = mlx_new_window(info.mlx, 1920, 1080, "Hello world!");
// // 	info.data.img = mlx_new_image(info.mlx, 1920, 1080);
// // 	info.data.addr = mlx_get_data_addr(info.data.img, &info.data.bits_per_pixel, &info.data.line_length,
// // 								 &info.data.endian);
// // 	info.player.pos_x = 12;
// // 	info.player.pos_y = 13;
	
// // 	mlx_put_image_to_window(info.mlx, info.win, info.data.img, 0, 0);
// // 	// mlx_loop(info.mlx);

// // 	mlx_loop_hook(info.mlx, &all_main, &info);
// // 	mlx_hook(info.win, 2, 0, &check_press, &info);
// // 	mlx_hook(info.win, 3, 0, &check_release, &info);

// // 	mlx_loop(info.mlx);
// // }