/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:40:34 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/25 10:40:38 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx(t_so_long *so_long)
{
	if (!so_long->win_ptr)
		return ;
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	if (!so_long->mlx_ptr)
		return ;
	mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
}
