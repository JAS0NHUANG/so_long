/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:47:03 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/19 16:54:31 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

void	init_node(t_list *node, int fd)
{
	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!node)
		return ;
	node->fd = fd;
	node->next = NULL;
	node->cont = (char *)malloc(sizeof(char) * 1);
	if (!node->cont)
		return ;
	(node->cont)[0] = '\0';
}
