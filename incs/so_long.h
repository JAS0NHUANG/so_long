/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:46:56 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 10:14:11 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifdef __linux__
#  include "../mlx/mlx.h"
#  define XK_ESCAPE 65307
#  define XK_W 119
#  define XK_A 97
#  define XK_S 115
#  define XK_D 100
# else
#  include <mlx.h>
#  define XK_ESCAPE 53
#  define XK_W 13
#  define XK_A 0
#  define XK_S 1
#  define XK_D 2
# endif

# include "./so_long_structs.h"
# include "../libft/libft.h"

typedef enum e_errors
{
	ERR_ARGUMENT = 1,
	ERR_NOT_BER,
	ERR_OPEN_FILE,
	ERR_WALL,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COIN,
	ERR_WIDTH,
	ERR_EMPTY,
	ERR_CHAR,
	ERR_MLX,
}	t_errors;

void	ft_exit_error(int error_code, t_so_long *so_long);
void	ft_check_argument(int ac, char **av);
void	ft_get_map(char *file, t_so_long *so_long);
void	ft_check_map(t_so_long *so_long);
void	ft_free_so_long(t_so_long *so_long);
void	ft_free_imgs(t_so_long *so_long);
void	ft_free_mlx(t_so_long *so_long);
void	ft_print_map_to_window(t_so_long *so_long);
void	ft_print_player(t_so_long *so_long, void *mlx_ptr, void *win_ptr);
void	ft_print_floor(t_so_long *so_long, int x, int y);
void	ft_print_exit(t_so_long *so_long, int x, int y);
void	ft_print_tile(t_so_long *so_long, int x, int y, void *img);
int		ft_key_event(int key, t_so_long *so_long);
int		ft_close(t_so_long *so_long);
void	ft_init_imgs(t_so_long *so_long, void *mlx_ptr);
void	ft_print_score(t_so_long *so_long, int is_finished);

#endif
