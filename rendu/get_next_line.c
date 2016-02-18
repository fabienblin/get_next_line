/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:03:37 by fblin             #+#    #+#             */
/*   Updated: 2016/02/14 15:24:28 by fblin            ###   ########.fr       */
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
	rdr->start = NULL;
	return (rdr);
}

int			ft_setrdrstart(t_reader *rdr, char **line)
{
	if ((rdr->start = ft_strchr(*line, '\n')))
	{
		*rdr->start = '\0';
		rdr->start++;
		return (1);
	}
	return (0);
}

int			ft_bufjoin(t_reader *rdr, char **line)
{
	int		read_ret;
	char	*buf;

	if (rdr->start)
	{
		*line = rdr->start;
		if (ft_setrdrstart(rdr, line))
			return (1);
	}
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((read_ret = read(rdr->fd, buf, BUFF_SIZE)) > 0)
	{
		*line = ft_strjoin(*line, buf);
		if (ft_setrdrstart(rdr, line))
			return (1);
		if (read_ret < BUFF_SIZE)
			return (1);
	}
	if (read_ret <= 0)
		return (read_ret);
	return (1);
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
