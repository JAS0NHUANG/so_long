/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:16:07 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/25 09:02:52 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_imgs(t_so_long *so_long)
{
	if (!so_long->map_imgs->t_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->r_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->l_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->b_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->m_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->c1_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->c2_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->c3_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->c4_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->exit_img)
		ft_exit_error(99, so_long);
	if (!so_long->map_imgs->floor_img)
		ft_exit_error(99, so_long);
}

void	*ft_set_file_to_image(t_so_long *so_long, char *path)
{
	void	*img;
	int		w;
	int		h;

	if (access(path, F_OK) != 0)
		return (NULL);
	img = mlx_xpm_file_to_image(so_long->mlx_ptr, path, &w, &h);
	return (img);
}

void	ft_init_map_imgs(t_so_long *so_long)
{
	t_map_imgs	*map_imgs;

	map_imgs = malloc(sizeof(t_map_imgs) * 1);
	if (!map_imgs)
		exit(1);
	so_long->map_imgs = map_imgs;
	map_imgs->t_img = ft_set_file_to_image(so_long, "imgs/t_wall.xpm");
	map_imgs->r_img = ft_set_file_to_image(so_long, "imgs/r_wall.xpm");
	map_imgs->l_img = ft_set_file_to_image(so_long, "imgs/l_wall.xpm");
	map_imgs->b_img = ft_set_file_to_image(so_long, "imgs/b_wall.xpm");
	map_imgs->m_img = ft_set_file_to_image(so_long, "imgs/m_wall.xpm");
	map_imgs->c1_img = ft_set_file_to_image(so_long, "imgs/corner1.xpm");
	map_imgs->c2_img = ft_set_file_to_image(so_long, "imgs/corner2.xpm");
	map_imgs->c3_img = ft_set_file_to_image(so_long, "imgs/corner3.xpm");
	map_imgs->c4_img = ft_set_file_to_image(so_long, "imgs/corner4.xpm");
	map_imgs->exit_img = ft_set_file_to_image(so_long, "imgs/exit.xpm");
	map_imgs->floor_img = ft_set_file_to_image(so_long, "imgs/floor.xpm");
	ft_check_imgs(so_long);
}

void	ft_init_coins(t_so_long *so_long, void *mlx_ptr)
{
	t_coins		*coins;
	int			w;
	int			h;

	coins = malloc(sizeof(t_coins) * 1);
	if (!coins)
		exit(1);
	so_long->coins = coins;
	coins->count = 0;
	coins->img = mlx_xpm_file_to_image(mlx_ptr, "imgs/coin.xpm", &w, &h);
}

void	ft_init_imgs(t_so_long *so_long, void *mlx_ptr)
{
	ft_init_map_imgs(so_long);
	ft_init_coins(so_long, mlx_ptr);
}
