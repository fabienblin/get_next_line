/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:03:37 by fblin             #+#    #+#             */
/*   Updated: 2016/02/12 18:48:39 by fblin            ###   ########.fr       */
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
	rdr->fd = fd;
	ft_bzero(rdr->start, BUFF_SIZE);
	return (rdr);
}
/*
#include <stdio.h>
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
*/
void		*ft_realloc(void *ptr, size_t ptr_s, size_t new_s)
{
	void	*tmp;

	if (!(tmp = (void *)ft_memalloc(new_s)))
		return (NULL);
	tmp = ft_memmove(tmp, ptr, ptr_s);
	ft_memdel(&ptr);
	return (tmp);
}

int			ft_bufjoin(t_reader *rdr, char **line)
{
	int		read_ret;
	char	*buf;
	char	*n;
	void	*tmp;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	/*if (rdr->start)
	{
		printf("a\n");
		tmp = *line;
		*line = ft_strjoin(rdr->start, *line);
	//	ft_memdel(&tmp);
	//	ft_strdel(&rdr->start);
	}*/
	while ((read_ret = read(rdr->fd, buf, BUFF_SIZE)) > 0
			&& !(n = ft_strchr(buf, '\n')))
	{
		printf("line = %s\t%p\nrealloc(line)\nread-ret=%d\n", *line, *line, read_ret);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
	//	ft_memdel(&tmp);
	}
	if (rdr->start[0])
	{
		printf("b\n");
		tmp = *line;
		*line = ft_strjoin(rdr->start, *line);
	//	ft_memdel(&tmp);
	//	ft_strdel(&(rdr->start));
	}
	if (n)
	{
		printf("c\n");
		tmp = *line;
		*line = ft_strjoin(*line, buf);
	//	ft_memdel(&tmp);
		rdr->start = ft_strchr(n, '\n');
	}
	//si il y a un start alors :
		//concat start et line
	//si il y a un \n dans buf alors :
		//concat line et buf
		//t
		//reset start
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

	*line = NULL;
	if (fd < 0 || fd > 256)
		return (-1);
	if (!(rdr = ft_getreader(fd, &rdr_lst)))
		return (-1);
	return (ft_bufjoin(rdr, line));
}
