/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:06:36 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/10 06:17:47 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	tempo_parser(char *line, t_info *info, int fd)
{
	if (line[0] == 'R' && line[1] == ' ')
		parser_resolution(line, &info->resol);
	if (ft_strchr("NSWE", line[0]) && ft_strchr("OEAP ", line[1]))
		parser_texture(line, &info->texture);
	if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
		parser_color(line, info);
	if (is_map(line))
		parser_map_row(&info->map, fd, line);
	return (0);
}

void	ft_print_all(t_info info)
{
	printf("resol is R\n   width:%d\n   heigth:%d\n\n", info.resol.width, info.resol.heigth);
	printf("texture is\n  EA %s\n  NP  %s\n  SP %s\n  WP %s\n  S %s\n", info.texture.east_path, info.texture.north_path, info.texture.south_path, info.texture.west_path, info.texture.sprite_path);
	printf("C_COlor red %d\nC_COlor green %d\nC_COlor blue %d\n", info.c_color.red, info.c_color.green, info.c_color.blue);
	printf("F_color red %d\nF_color green %d\nF_color blue %d\n", info.f_color.red, info.f_color.green, info.f_color.blue);
	printf("\ninfo->map.count_row is %d\ninfo->map.max %d\n", info.map.count,info.map.max);
}

int		parser(t_info *info)
{
	int		fd;
	int		i;
	char	*line;

	info->map.count = -1;

	fd = open("file", O_RDONLY);
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		{
			i = get_next_line(fd, &line);
			continue ;
		}
		tempo_parser(line, info, fd);
		i = get_next_line(fd, &line);
	}
	tempo_parser(line, info, fd);
	ft_print_all(*info);
	return (0);
}