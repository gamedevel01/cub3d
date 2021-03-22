/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:09:34 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/22 10:21:19 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	char *line;
	t_info	info;
	set_info(&info);
	printf("\nSTOP\n");
	parser(&info);
	ft_print_all(info);
	// printf("\nresol is R %d %d\n",info.resol.width, info.resol.heigth);
	// printf("\nNO texture is %s", info.texture_info.north_path);
	// printf("\nWE texture is %s", info.texture_info.west_path);
	// printf("\nColor is F %i %i %i", info.f_color.red, info.f_color.green, info.f_color.blue);
}