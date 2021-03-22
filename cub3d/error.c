/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:41:08 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/19 19:18:23 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *text)
{
	ft_putstr_fd(text, 1);
	exit(0);
}

void	ft_wich_error(int error)
{
	if (error == 0)
		ft_print_error("ДОДЕЛАЙ\n");
	if (error == -1)
		ft_print_error("error\nWRONG RESOL\n");
	if (error == -2)
		ft_print_error("error\nWRONG TEXTURE\n");
	if (error == -3)
		ft_print_error("error\nWRONG COLOR\n");
	if (error == -4)
		ft_print_error("error\nKEY DUPLICATE\n");
	if (error == -5)
		ft_print_error("error\nKEY LOW\n");
}

// void	check_release(int key, t_info *info)
// {
// 	if (key == 53)
// 		exit(0);
//  if (key == A)
// }


/*# define WRONG_RESOL -1
# define WRONG_TEXTURE -2
# define WRONG_COLOR -3
# define KEY_DUPLICATE -4
# define KEY_LOW -5*/