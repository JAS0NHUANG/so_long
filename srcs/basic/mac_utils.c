/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:38:36 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 09:54:09 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx(t_so_long *so_long)
{
	if (!(so_long->win_ptr))
		return ;
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	if (!so_long->mlx_ptr)
		return ;
	free(so_long->mlx_ptr);
}
