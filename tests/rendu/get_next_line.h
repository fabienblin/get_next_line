/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <fblin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:38 by fblin             #+#    #+#             */
/*   Updated: 2016/02/12 18:48:40 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# define RDR ((t_reader *)((*rdr_lst)->content))

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				get_next_line(int const fd, char **line);

typedef	struct	s_reader
{
	int			fd;
	char		start[BUFF_SIZE];
}				t_reader;
#endif
