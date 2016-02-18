/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:03:37 by fblin             #+#    #+#             */
/*   Updated: 2016/01/13 17:18:14 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


char	*ft_bufjoin(t_reader *rdr)
{
	char	*eoln;
	int		read_ret;
	char	*buf;

	//malloc de buf
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (NULL);
	//initialisation de buf
	read_ret = read(rdr->fd, buf, BUFF_SIZE);
	ft_putnbr(read_ret);
	//si le read est bien passe
	if (read_ret > 0)
	{
		// si il n'y a pas de fin de ligne (eoln)
		if (!(eoln = ft_strchr(buf, '\n')))
		{
			//alors concatenner le buf du read suivant
			if (!(buf = ft_strjoin(buf, ft_bufjoin(rdr))))
			{
				return (NULL);
			}
		}
		//s'il y a un \n
		else
		{
			//mettre le reader sur eoln
			rdr->start = eoln + 1;
			//definir buf sans la suite du \n
			buf = ft_strsub(buf, 0, eoln - buf);
		}
	}
	//si le read a echoue
	else
	{
		return (NULL);
	}
	return (buf);
}

t_reader	*ft_getreader(int fd, t_list *rdr_lst)
{
	t_reader	*rdr;

	if (!rdr_lst->content)
	{
		rdr_lst->content = ft_rdrnew(fd);
		rdr_lst->content_size = sizeof(t_reader);
		rdr_lst->next = NULL;
	}
	rdr = ((t_reader *)rdr_lst->content);
	if (rdr->fd != fd)
	{
		if (!rdr_lst->next)
		{
			rdr_lst->next = ft_lstnew(ft_rdrnew(fd), sizeof(t_reader));
		}
		ft_getreader(fd, rdr_lst->next);
	}
	else
	{
		return (rdr);
	}
	return (NULL);
}

void	print_rdrlst(t_list *rdr_lst)
{
	ft_putendl("rdr -----");
	if (rdr_lst)
	{
		if (rdr_lst->content)
		{
			ft_putstr("fd : "); ft_putnbr(((t_reader *)rdr_lst->content)->fd); ft_putchar('\n');
//			ft_putstr("start : "); ft_putendl(((t_reader *)rdr_lst->content)->start);
			print_rdrlst(rdr_lst->next);
		}
	}
	else
	{
		ft_putendl("end of rdr_lst");
	}
}

// fonction appelee en boucle pour lire chaque ligne une a une
int		get_next_line(int const fd, char **line)
{
	static t_list	rdr_lst;
	t_reader 		*rdr;
	char			*buf;

	rdr_lst.content = ft_rdrnew(fd);
	if (line)
	{
		ft_putendl("GNL : START");
		if (!(rdr = ft_getreader(4, &rdr_lst)))
			return (-1);
		ft_putendl("\tGNL : rdr set");
		print_rdrlst(&rdr_lst);
(void)buf;
(void)fd;
//		ft_putnbr(rdr->fd);
//		if (!(buf = ft_bufjoin(rdr)))
//			return (-1);
//		return (1);
//		*line = buf;
	}
	return (-1);
}
