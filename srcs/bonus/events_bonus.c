/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:40:42 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 10:00:57 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_so_long *so_long)
{
	ft_free_so_long(so_long);
	exit(0);
}

void	ft_move_player_print(t_so_long *so_long, int x, int y, int *go_to)
{
	if (so_long->map->map_array[y][x] == 'E')
		ft_print_tile(so_long, x, y, so_long->map_imgs->exit_img);
	else
		ft_print_tile(so_long, x, y, so_long->map_imgs->floor_img);
	so_long->player->x = go_to[0];
	so_long->player->y = go_to[1];
	so_long->player->moves++;
	ft_print_tile(so_long, go_to[0], go_to[1], so_long->player->img);
	ft_print_score(so_long, 0);
}

int	ft_check_go_to(t_so_long *so_long, int x, int y)
{
	if (so_long->map->map_array[y][x] == '1')
		return (-1);
	if (so_long->map->map_array[y][x] == 'E')
	{
		if (so_long->coins->count == 0 && so_long->is_finished != 1)
		{
			so_long->player->moves++;
			ft_print_tile(so_long, so_long->player->x, so_long->player->y,
				so_long->map_imgs->floor_img);
			ft_print_tile(so_long, x, y, so_long->player->img);
			ft_print_score(so_long, 1);
			return (1);
		}
		return (0);
	}
	if (so_long->map->map_array[y][x] == 'C')
	{
		so_long->coins->count--;
		so_long->map->map_array[y][x] = '0';
		return (0);
	}
	return (0);
}

void	ft_move_player(t_so_long *so_long, int x, int y, int dir)
{
	int	go_to[2];

	if (so_long->is_finished && so_long->is_finished == 1)
		return ;
	go_to[0] = x;
	go_to[1] = y;
	if (dir == XK_A)
		go_to[0]--;
	if (dir == XK_D)
		go_to[0]++;
	if (dir == XK_W)
		go_to[1]--;
	if (dir == XK_S)
		go_to[1]++;
	so_long->is_finished = ft_check_go_to(so_long, go_to[0], go_to[1]);
	if (so_long->is_finished == -1)
		return ;
	if (so_long->is_finished != 1)
		ft_move_player_print(so_long, x, y, go_to);
}

int	ft_key_event(int key, t_so_long *so_long)
{
	if (key == XK_ESCAPE)
		ft_close(so_long);
	if (key == XK_A || key == XK_D || key == XK_W || key == XK_S)
		ft_move_player(so_long, so_long->player->x, so_long->player->y, key);
	return (0);
}
