/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:10:10 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 08:10:12 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char *base)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (base[index1])
	{
		index2 = index1 + 1;
		while (base[index2])
		{
			if (base[index1] == base[index2])
				return (0);
			index2++;
		}
		index1++;
	}
	return (0);
}

static char	*ft_reversestr(char *str)
{
	int		index;
	int		str_len;
	char	tmp[64];
	char	*result;

	index = 0;
	str_len = ft_strlen(str);
	while (str_len > index)
	{
		tmp[index] = str[str_len - index - 1];
		index++;
	}
	tmp[index] = '\0';
	result = tmp;
	return (result);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		index;
	int		base_len;
	char	tmp[64];
	char	*result;

	index = 0;
	base_len = ft_strlen(base);
	if (base_len < 1 || !ft_check_base(base))
		return (NULL);
	while (nbr >= (unsigned long long)base_len)
	{
		tmp[index] = base[nbr % base_len];
		nbr /= base_len;
		index++;
	}
	tmp[index] = base[nbr % base_len];
	tmp[index + 1] = '\0';
	result = ft_reversestr(tmp);
	return (result);
}
