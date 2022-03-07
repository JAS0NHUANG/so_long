/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:04:06 by jahuang           #+#    #+#             */
/*   Updated: 2021/10/31 16:04:07 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			count;
	unsigned char	*s_holder;

	count = 0;
	s_holder = (unsigned char *)s;
	while (s_holder[count])
		count++;
	return (count);
}
