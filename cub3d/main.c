/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:09:34 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/14 20:15:38 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	char *line;
	t_info	info;
	set_info(&info);
	parser(&info);
	void	ft_print_all(t_info info);
	printf("resol is R %d %d\n",info.resol.width, info.resol.heigth);
	printf("\nNO texture is %s", info.texture.north_path);
	printf("\nWE texture is %s", info.texture.west_path);
	printf("\nColor is F %i %i %i", info.f_color.red, info.f_color.green, info.f_color.blue);
}