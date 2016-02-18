/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:03:37 by fblin             #+#    #+#             */
/*   Updated: 2016/02/18 18:09:19 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** RIP David Bowie 08/01/1947 - 10/01/2016
*/
#include "get_next_line.h"

t_reader	*ft_rdrnew(int fd)
{
	t_reader *rdr;

	if (!(rdr = (t_reader *)malloc(sizeof(t_reader))))
		return (0);
	ft_bzero(rdr, sizeof(t_reader));
	FD = fd;
	return (rdr);
}
#include <stdio.h>
/*
int			ft_setrdrstart(t_reader *rdr, char *str)
{
	if ((rdr->start = ft_strchr(str, '\n')))
	{
		*rdr->start = '\0';
		rdr->start++;
		return (1);
	}
	return (0);
}

void		*ft_realloc(void *ptr, size_t ptr_s, size_t new_s)
{
	void	*tmp;

	if (!(tmp = (void *)ft_memalloc(new_s)))
		return (NULL);
	tmp = ft_memmove(tmp, ptr, ptr_s);
	ft_memdel(&ptr);
	return (tmp);
}
*/

void		*ft_memcat(void *mem1, void *mem2, size_t mem1_s, size_t mem2_s)
{
	char *cat;

	cat = NULL;
	if (!(cat = (char *)malloc(sizeof(char) * (mem1_s + mem2_s))))
		return (NULL);
	ft_memcpy(cat, mem1, mem1_s);
	ft_memcpy(cat + mem1_s, mem2, mem2_s);
	return (cat);
}

int			ft_bufjoin(t_reader *rdr, char **line)
{
	int		read_ret;
	char	*buf;
	char	*n;
	void	*tmp;
	size_t	line_len = 0;
	size_t	eol_len = 0;

/*	if (EOL)
	{
		*line = ft_strdup(EOL);
		int j = EOL - BUFFER;
		ft_memcpy(BUFFER, EOL, EOL - BUFFER);
		while (j--)
		{
			rdr->buffer[j] = 0;
		}
	}
*/
	while ((read_ret = read(FD, BUFFER, BUFF_SIZE)) > 0
			&& !EOL)
	{
		*line = ft_memcat(*line, BUFFER, line_len, read_ret);
		ft_bzero(BUFFER, BUFF_SIZE);
		line_len += read_ret;
	}
	if (EOL)
	{
		*line = ft_memcat(*line, BUFFER, line_len, EOL - BUFFER + 1);
		*ft_strchr(*line, '\n') = 0;
	}
	return ((read_ret > 0) ? 1 : read_ret);
}

t_reader	*ft_getreader(int fd, t_list **rdr_lst)
{
	if (!*rdr_lst)
	{
		*rdr_lst = ft_lstnew(NULL, 0);
	}
	if (!(*rdr_lst)->content)
	{
		(*rdr_lst)->content = ft_rdrnew(fd);
		(*rdr_lst)->next = NULL;
	}
	if (RDR->fd != fd)
	{
		return (ft_getreader(fd, &((*rdr_lst)->next)));
	}
	return (RDR);
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*rdr_lst = NULL;
	t_reader		*rdr;

	if (fd < 0 || fd > 256)
		return (-1);
	if (!(rdr = ft_getreader(fd, &rdr_lst)))
		return (-1);
	if (BUFFER)
	{	ft_putendl(BUFFER);
	ft_putendl("-------");}
	return (ft_bufjoin(rdr, line));
}
