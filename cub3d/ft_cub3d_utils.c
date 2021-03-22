/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:19:52 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/19 19:19:25 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mass_strlen(char **mass)
{
	int i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

void	set_info(t_info *info)
{
	info->c_color.blue = 0;
	info->c_color.green = 0;
	info->c_color.blue = 0;
	info->f_color.blue = 0;
	info->f_color.green = 0;
	info->f_color.blue = 0;
	info->resol.heigth = 0;
	info->resol.width = 0;
	info->texture_info.east_path = NULL;
	info->texture_info.north_path = NULL;
	info->texture_info.south_path = NULL;
	info->texture_info.sprite_path = NULL;
	info->texture_info.west_path = NULL;
}
