/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:48 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 08:02:19 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_coin(t_so_long *so_long)
{
	int		coin_count;
	int		i;
	int		j;

	coin_count = 0;
	i = 0;
	while (i < so_long->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(so_long->map->map_array[i]))
		{
			if (so_long->map->map_array[i][j] == 'C')
				coin_count++;
			j++;
		}
		i++;
	}
	if (coin_count < 1)
		ft_exit_error(ERR_COIN, so_long);
}

static void	ft_check_player_exit(t_so_long *so_long)
{
	int		player_count;
	int		exit_count;
	int		i;
	int		j;

	player_count = 0;
	exit_count = 0;
	i = 0;
	while (i < so_long->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(so_long->map->map_array[i]))
		{
			if (so_long->map->map_array[i][j] == 'P')
				player_count++;
			if (so_long->map->map_array[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		ft_exit_error(ERR_PLAYER, so_long);
	if (exit_count < 1)
		ft_exit_error(ERR_EXIT, so_long);
}

static void	ft_check_wall_and_width(t_so_long *so_long)
{
	int		line_width;
	int		i;
	int		j;

	i = 0;
	if (so_long->map->width == 0)
		ft_exit_error(ERR_EMPTY, so_long);
	while (i < so_long->map->height)
	{
		line_width = (int)ft_strlen(so_long->map->map_array[i]);
		if (line_width == 0)
			ft_exit_error(ERR_EMPTY, so_long);
		if (so_long->map->width != line_width)
			ft_exit_error(ERR_WIDTH, so_long);
		j = 0;
		while (j < so_long->map->width)
		{
			if (so_long->map->map_array[i][j] != '1' && \
				(j == 0 || i == 0 || i == so_long->map->height - 1 || \
				j == so_long->map->width - 1))
				ft_exit_error(ERR_WALL, so_long);
			j++;
		}
		i++;
	}
}

static void	ft_check_char(t_so_long *so_long)
{
	int		i;
	int		j;

	i = 0;
	while (i < so_long->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(so_long->map->map_array[i]))
		{
			if (so_long->map->map_array[i][j] != '1' && \
				so_long->map->map_array[i][j] != '0' && \
				so_long->map->map_array[i][j] != 'P' && \
				so_long->map->map_array[i][j] != 'E' && \
				so_long->map->map_array[i][j] != 'C')
			{
				ft_exit_error(ERR_CHAR, so_long);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_map(t_so_long *so_long)
{
	ft_check_char(so_long);
	ft_check_wall_and_width(so_long);
	ft_check_player_exit(so_long);
	ft_check_coin(so_long);
	return ;
}
