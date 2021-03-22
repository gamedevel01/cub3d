/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:29:33 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/10 10:58:36 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser_color(char *str, t_info *info)
{
	if (str[0] == 'C' && str[1] == ' ')
	{
		info->c_color.red = ft_atoi(ft_split(&str[2], ',')[0]);
		info->c_color.green = ft_atoi(ft_split(&str[2], ',')[1]);
		info->c_color.blue = ft_atoi(ft_split(&str[2], ',')[2]);
		return ;
	}
	if (str[0] == 'F' && str[1] == ' ')
	{
		info->f_color.red = ft_atoi(ft_split(&str[2], ',')[0]);
		info->f_color.green = ft_atoi(ft_split(&str[2], ',')[1]);
		info->f_color.blue = ft_atoi(ft_split(&str[2], ',')[2]);
		return ;
	}
	ft_wich_error(WRONG_COLOR);
}
