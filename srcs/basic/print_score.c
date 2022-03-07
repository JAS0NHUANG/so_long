/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:59:03 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/20 16:30:24 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_score(t_so_long *so_long, int is_finished)
{
	int		width;
	int		height;
	int		index;
	char	*str;
	char	*moves_str;

	width = so_long->map->width;
	height = so_long->map->height;
	index = 0;
	moves_str = ft_itoa(so_long->player->moves);
	while (index < width)
	{
		ft_print_tile(so_long, index, height, so_long->map_imgs->floor_img);
		index++;
	}
	if (is_finished == 1)
		str = "Your final score: ";
	else
		str = "Total moves: ";
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
		(width * 64) / 2 - 32, height * 64 + 8, 0xFFFFFF, str);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr,
		(width * 64) / 2 - 2, height * 64 + 20, 0xFFFFFF, moves_str);
	if (moves_str)
		free(moves_str);
}
