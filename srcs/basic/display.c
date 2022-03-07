/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:43:37 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 07:49:59 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_so_long *so_long, int i, int j)
{
	int		w;
	int		h;

	so_long->player = malloc(sizeof(t_player) * 1);
	if (!so_long->player)
		exit(1);
	so_long->player->moves = 0;
	so_long->player->img = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"imgs/player.xpm", &w, &h);
	if (!so_long->player->img)
		exit(1);
	so_long->player->x = j;
	so_long->player->y = i;
}

void	ft_print_tile(t_so_long *so_long, int x, int y, void *img)
{
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		img, x * 64, y * 64);
}

static void	ft_print_wall(t_so_long *so_long, int x, int y)
{
	if (y == 0 && x == 0)
		ft_print_tile(so_long, x, y, so_long->map_imgs->c1_img);
	else if (y == 0 && x == so_long->map->width - 1)
		ft_print_tile(so_long, x, y, so_long->map_imgs->c2_img);
	else if (y == so_long->map->height - 1 && x == 0)
		ft_print_tile(so_long, x, y, so_long->map_imgs->c3_img);
	else if (y == so_long->map->height - 1 && \
		x == so_long->map->width - 1)
		ft_print_tile(so_long, x, y, so_long->map_imgs->c4_img);
	else if (y == 0)
		ft_print_tile(so_long, x, y, so_long->map_imgs->t_img);
	else if (y == so_long->map->height - 1)
		ft_print_tile(so_long, x, y, so_long->map_imgs->b_img);
	else if (x == 0)
		ft_print_tile(so_long, x, y, so_long->map_imgs->l_img);
	else if (x == so_long->map->width - 1)
		ft_print_tile(so_long, x, y, so_long->map_imgs->r_img);
	else
		ft_print_tile(so_long, x, y, so_long->map_imgs->m_img);
}

static void	ft_print_map(t_so_long *so_long)
{
	int			i;
	int			j;

	i = 0;
	while (i < so_long->map->height)
	{
		j = 0;
		while (j < so_long->map->width)
		{
			if (so_long->map->map_array[i][j] == 'P')
				ft_init_player(so_long, i, j);
			if (so_long->map->map_array[i][j] == '1')
				ft_print_wall(so_long, j, i);
			if (so_long->map->map_array[i][j] == 'E')
				ft_print_tile(so_long, j, i, so_long->map_imgs->exit_img);
			if (so_long->map->map_array[i][j] == 'C')
			{
				ft_print_tile(so_long, j, i, so_long->coins->img);
				so_long->coins->count++;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_map_to_window(t_so_long *so_long)
{
	ft_init_imgs(so_long, so_long->mlx_ptr);
	ft_print_map(so_long);
	ft_print_tile(so_long, so_long->player->x, so_long->player->y,
		so_long->player->img);
}
