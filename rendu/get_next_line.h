/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fblin <fblin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/01/02 13:22:38 by fblin        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 12:00:13 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 90

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				get_next_line(int const fd, char **line);

typedef	struct	s_reader
{
	int				fd;
	char			*start;
}				t_reader;
#endif
