/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:49:07 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/25 12:31:03 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

typedef struct s_map
{
	int		height;
	int		width;
	char	**map_array;
}	t_map;

typedef struct s_image
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
	int		moves;
	char	*moves_str;
}	t_player;

typedef struct s_coins
{
	int		count;
	void	*img;
}	t_coins;

typedef struct s_map_imgs
{
	void	*c1_img;
	void	*c2_img;
	void	*c3_img;
	void	*c4_img;
	void	*t_img;
	void	*b_img;
	void	*l_img;
	void	*r_img;
	void	*m_img;
	void	*floor_img;
	void	*exit_img;
}	t_map_imgs;

typedef struct s_so_long
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			is_finished;
	t_map		*map;
	t_player	*player;
	t_coins		*coins;
	t_map_imgs	*map_imgs;
}	t_so_long;

#endif
