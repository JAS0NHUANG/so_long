/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:59:03 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/20 21:00:39 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_score_background(t_so_long *so_long)
{
	int		index;

	index = 0;
	while (index < so_long->map->width)
	{
		ft_print_tile(so_long, index, so_long->map->height,
			so_long->map_imgs->floor_img);
		index++;
	}
}

void	ft_print_score(t_so_long *so_long, int is_finished)
{
	int		width;
	int		height;
	char	*str;
	char	*moves_str;

	width = so_long->map->width;
	height = so_long->map->height;
	moves_str = ft_itoa(so_long->player->moves);
	ft_print_score_background(so_long);
	if (is_finished == 1)
		str = "Your final score: ";
	else
		str = "Total moves: ";
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
		(width * 64) / 2 - 36, (height * 64) + 12, 0xFFFFFF, str);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
		(width * 64) / 2 - 2, (height * 64) + 32, 0xFFFFFF, moves_str);
	if (is_finished == 1)
	{
		mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
			(width * 64) / 2 - 72, (height * 64) + 48, 0xFFFFFF,
			"(press \"esc\" to exit. ^_^)");
	}
	if (moves_str)
		free(moves_str);
}
