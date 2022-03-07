/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:25:25 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/25 10:39:05 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_coins(t_so_long *so_long)
{
	if (!so_long->coins)
		return ;
	if (so_long->coins->img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->coins->img);
	free(so_long->coins);
}

void	ft_free_player(t_so_long *so_long)
{
	if (!so_long->player)
		return ;
	if (so_long->player->img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->player->img);
	free(so_long->player);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->map_array)
	{
		while (i < map->height)
		{
			free(map->map_array[i]);
			i++;
		}
		free(map->map_array);
	}
	free(map);
}

void	ft_free_so_long(t_so_long *so_long)
{
	if (!so_long)
		return ;
	ft_free_map(so_long->map);
	ft_free_player(so_long);
	ft_free_coins(so_long);
	ft_free_imgs(so_long);
	ft_free_mlx(so_long);
	if (so_long)
		free(so_long);
}
