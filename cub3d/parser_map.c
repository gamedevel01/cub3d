/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 06:23:58 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/22 11:34:52 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_map(char *line)
{
	while (*line)
	{
		if (ft_strchr("01NSWE ", *line) == 0)
			return (-1);
		line += 1;
	}
	return (1);
}

int			parser_map(char *line, t_info *info, int fd)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("\nft_strlen is %i\n", ft_strlen(line));
		info->map[count] = malloc(sizeof(char) * ft_strlen(line));
		j = 0;
		while (line[j])
		{
			info->map[count][j] = line[j];
			j++;
		}
		count += 1;
		free(*line);
	}
	
	j = 0;
		while (line[j] != '\n')
		{
			info->map[i][j] = line[j];
			j++;
		}
		free(*line);
	return (1);
}
