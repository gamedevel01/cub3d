/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:19:36 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/19 19:00:59 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser_texture(char *line, t_texture_info *texture)
{
	// if (ft_mass_strlen(ft_split(line, ' ')) != 2)
	// 	ft_wich_error(WRONG_TEXTURE);
	// if (open(line, O_RDONLY) == -1)
	// 	ft_wich_error(WRONG_TEXTURE);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && texture->north_path == NULL)
		texture->north_path = ft_split(line, ' ')[1];
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && texture->south_path == NULL)
		texture->south_path = ft_split(line, ' ')[1];
	else if (line[0] == 'W' && line[1] == 'E' &&line[2] == ' '  && texture->west_path == NULL)
		texture->west_path = ft_split(line, ' ')[1];
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && texture->east_path == NULL)
		texture->east_path = ft_split(line, ' ')[1];
	else if (line[0] == 'S' && line[1] == ' ' && texture->sprite_path == NULL)
		texture->sprite_path = ft_split(line, ' ')[1];
	else (WRONG_TEXTURE);
}
