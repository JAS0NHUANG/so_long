/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:54:58 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/25 07:55:35 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_so_long(t_so_long *so_long)
{
	so_long->coins = NULL;
	so_long->mlx_ptr = NULL;
	so_long->win_ptr = NULL;
	so_long->is_finished = 0;
	so_long->map = NULL;
	so_long->player = NULL;
	so_long->coins = NULL;
	so_long->map_imgs = NULL;
}

void	ft_start_so_long(t_so_long *so_long)
{
	int	w;
	int	h;

	w = so_long->map->width * 64;
	h = so_long->map->height * 64;
	so_long->mlx_ptr = mlx_init();
	if (!so_long->mlx_ptr)
		ft_exit_error(ERR_MLX, so_long);
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, w, h,
			"so_long");
	if (!so_long->win_ptr)
		ft_exit_error(ERR_MLX, so_long);
	ft_print_map_to_window(so_long);
	mlx_key_hook(so_long->win_ptr, &ft_key_event, so_long);
	mlx_hook(so_long->win_ptr, 17, 1l << 0, &ft_close, so_long);
	mlx_loop(so_long->mlx_ptr);
	ft_free_so_long(so_long);
}

int	main(int ac, char **av)
{
	t_so_long	*so_long;

	ft_check_argument(ac, av);
	so_long = malloc(sizeof(t_so_long) * 1);
	if (!so_long)
		return (1);
	ft_init_so_long(so_long);
	ft_get_map(av[1], so_long);
	ft_check_map(so_long);
	ft_start_so_long(so_long);
}
