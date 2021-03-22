/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:26:06 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/11 07:34:10 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_resol(t_resol resol)
{
	if (resol.width > RESOL_WIDTH_MAX || resol.heigth > RESOL_HEIGTH_MAX)
		ft_wich_error(WRONG_RESOL);
	if (resol.width == 0 || resol.heigth == 0)
		ft_wich_error(WRONG_RESOL);
}

void	parser_resolution(char *line, t_resol *resol)
{
	if (ft_mass_strlen(ft_split(line, ' ')) != 3)
		ft_wich_error(WRONG_RESOL);
	if (line[0] == 'R' && line[1] == ' ')
	{
		if (resol->width != 0)
			ft_wich_error(KEY_DUPLICATE);
		resol->width = ft_atoi(ft_split(line, ' ')[1]);
		resol->heigth = ft_atoi(ft_split(line, ' ')[2]);
		check_resol(*resol);
	}
}

// {
// t_resol		make_resol()
// 	t_resol test;
// }
