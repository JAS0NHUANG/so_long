/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <jahuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:49:56 by jahuang           #+#    #+#             */
/*   Updated: 2021/12/03 08:49:43 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "../libft.h"

typedef struct s_list
{
	int				fd;
	char			*cont;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
t_list				*get_node(int fd, t_list	**static_list);
int					init_node(t_list *node, int fd);
int					delete_node(int fd, t_list **static_list);
int					get_the_line(char **line, char **cont);
int					read_fd(int fd, t_list *fd_node);
int					join_and_free(char *buf, char **cont);
int					find_n(char *s);
int					update_cont(char **cont);
int					ft_memdel(void **ap);

#endif
