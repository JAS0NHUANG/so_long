/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:38:41 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 08:38:45 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_imgs(t_so_long *so_long)
{
	if (!so_long->map_imgs)
		return ;
	if (so_long->map_imgs->t_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->t_img);
	if (so_long->map_imgs->l_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->l_img);
	if (so_long->map_imgs->r_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->r_img);
	if (so_long->map_imgs->b_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->b_img);
	if (so_long->map_imgs->m_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->m_img);
	if (so_long->map_imgs->c1_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->c1_img);
	if (so_long->map_imgs->c2_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->c2_img);
	if (so_long->map_imgs->c3_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->c3_img);
	if (so_long->map_imgs->c4_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->c4_img);
	if (so_long->map_imgs->floor_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->floor_img);
	if (so_long->map_imgs->exit_img)
		mlx_destroy_image(so_long->mlx_ptr, so_long->map_imgs->exit_img);
	free(so_long->map_imgs);
}
