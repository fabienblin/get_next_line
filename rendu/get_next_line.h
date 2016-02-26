/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <fblin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:38 by fblin             #+#    #+#             */
/*   Updated: 2016/02/18 18:02:49 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2 
# define RDR ((t_reader *)((*rdr_lst)->content))
# define BUFFER (&rdr->buffer[0])
# define EOL ((char *)ft_memchr(BUFFER, '\n', BUFF_SIZE))
# define FD (rdr->fd)

# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

int				get_next_line(int const fd, char **line);

typedef	struct	s_reader
{
	int			fd;
	char		buffer[BUFF_SIZE];
}				t_reader;
#endif
