/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:59:08 by jahuang           #+#    #+#             */
/*   Updated: 2021/11/12 12:14:27 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# include "./get_next_line/get_next_line.h"

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct s_deque
{
	t_node			*head;
	t_node			*tail;
	int				length;
}					t_deque;

void				ft_putstr_fd(char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_itoa_base(int nbr, char *base);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);

/*
char				**ft_split(const char *s, char c);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
*/

#endif
