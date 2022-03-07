/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:34:54 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/17 12:35:04 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_dot_ber(char *file_name)
{
	int	index;

	index = 0;
	while (file_name[index])
	{
		if (ft_strncmp(&file_name[index], ".ber", 5) == 0)
			return ;
		index++;
	}
	ft_exit_error(ERR_NOT_BER, NULL);
}

void	ft_check_argument(int ac, char **av)
{
	if (ac != 2)
		ft_exit_error(ERR_ARGUMENT, NULL);
	ft_is_dot_ber(av[1]);
}
