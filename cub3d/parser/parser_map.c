/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 06:23:58 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/10 11:00:25 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_map(char *line)
{
	while (*line)
	{
		if (ft_strchr("1 ", *line))
		{
			line++;
			continue ;
		}
		return (0);
	}
	return (1);
}

void	parser_map_row(t_map *map, int fd, char *line)
{
	int		i;

	if (map->max == -1)
		map->max = ft_strlen(line);
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		if (map->max < ft_strlen(line))
			map->max = ft_strlen(line);
		map->count++;
		i = get_next_line(fd, &line);
	}
	if (map->max < ft_strlen(line))
		map->max = ft_strlen(line);
	map->count++;
}