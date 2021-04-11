/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:41:08 by bzelda            #+#    #+#             */
/*   Updated: 2021/03/17 16:50:07 by bzelda           ###   ########.fr       */
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
