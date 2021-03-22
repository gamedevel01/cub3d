/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:06:36 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/22 11:33:10 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	tempo_parser(char *line, t_info *info)
{
	if (is_map(line) == 1)
	{
		parser_map(&info, *line);
		return (0);
	}
	if (line[0] == 'R' && line[1] == ' ')
		parser_resolution(line, &info->resol);
	if (ft_strchr("NSWE", line[0]) && ft_strchr("OEAP ", line[1]))
		parser_texture(line, &info->texture_info);
	if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
		parser_color(line, info);
	return (0);
}

void	ft_print_all(t_info info)
{
	printf("resol is R\n   width:%d\n   heigth:%d\n\n", info.resol.width, info.resol.heigth);
	printf("texture is\n  EA %s\n  NP  %s\n  SP %s\n  WP %s\n  S %s\n", info.texture_info.east_path, info.texture_info.north_path, info.texture_info.south_path, info.texture_info.west_path, info.texture_info.sprite_path);
	printf("C_COlor red %d\nC_COlor green %d\nC_COlor blue %d\n", info.c_color.red, info.c_color.green, info.c_color.blue);
	printf("F_color red %d\nF_color green %d\nF_color blue %d\n", info.f_color.red, info.f_color.green, info.f_color.blue);
	// int i = 0;
	// while (i < 10)
	// {
	// 	printf("is %c", info.map[i][0]);
	// 	printf("is %c", info.map[i][1]);
	// 	printf("is %c", info.map[i][2]);
	// 	printf("is%c", info.map[i][3]);
	// 	printf("is%c", info.map[i][4]);
	// 	printf("is%c", info.map[i][5]);
	// 	printf("is%c", info.map[i][6]);
	// 	printf("is%c", info.map[i][7]);
	// 	printf("is%c", info.map[i][8]);
	// 	printf("is%c", info.map[i][9]);
	// 	i++;
	// 	printf("\n");
	// }
	printf("string is %s", info.map[0]);
}

int		parser(t_info *info)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("file", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
			continue ;
		tempo_parser(line, info);
	}
	tempo_parser(line, info);
	ft_print_all(*info);
	return (0);
}