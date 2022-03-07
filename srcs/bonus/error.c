/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:55:37 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/17 14:27:12 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_argument_error(int error_code)
{
	char	*error_message;

	error_message = NULL;
	if (error_code == ERR_ARGUMENT)
		error_message = "please provide one and only one map file.\n";
	if (error_code == ERR_NOT_BER)
		error_message = "map should be a \".ber\" file.\n";
	if (error_code == ERR_OPEN_FILE)
		error_message = "error opening map file.\n";
	return (error_message);
}

static char	*ft_map_error(int error_code)
{
	char	*error_message;

	error_message = NULL;
	if (error_code == ERR_WALL)
		error_message = "invalid map. map is not surounded by walls.\n";
	if (error_code == ERR_PLAYER)
		error_message = "invalid map. must have one and only one player.\n";
	if (error_code == ERR_EXIT)
		error_message = "invalid map. no exit.\n";
	if (error_code == ERR_COIN)
		error_message = "invalid map. no collectible.\n";
	if (error_code == ERR_WIDTH)
		error_message = "invalid map. map is not a rectangle.\n";
	if (error_code == ERR_EMPTY)
		error_message = "invalid map. map contains empty line.\n";
	if (error_code == ERR_CHAR)
		error_message = "invalid map. map contains illigal character.\n";
	return (error_message);
}

void	ft_exit_error(int error_code, t_so_long *so_long)
{
	char	*error_message;

	error_message = "undefined error.\n";
	if (error_code >= ERR_ARGUMENT && error_code <= ERR_OPEN_FILE)
		error_message = ft_argument_error(error_code);
	if (error_code >= ERR_WALL && error_code <= ERR_CHAR)
		error_message = ft_map_error(error_code);
	if (error_code >= ERR_MLX)
		error_message = "error initializing minilibx.\n";
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_message, 2);
	if (so_long)
		ft_free_so_long(so_long);
	exit(error_code);
}
