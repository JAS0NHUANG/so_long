/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:43:56 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 08:43:59 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int	printnbr;

	if (nbr == -2147483648)
	{
		ft_putchar_fd('-', fd);
		nbr = -(nbr / 10);
		ft_putnbr_fd(nbr, fd);
		ft_putnbr_fd(8, fd);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if ((nbr / 10) != 0)
		ft_putnbr_fd(nbr / 10, fd);
	printnbr = nbr % 10 + 48;
	ft_putchar_fd(printnbr, fd);
	return ;
}
