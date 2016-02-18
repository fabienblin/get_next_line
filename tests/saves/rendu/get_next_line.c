/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:03:37 by fblin             #+#    #+#             */
/*   Updated: 2016/01/08 15:59:54 by fblin            ###   ########.fr       */
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

	write (1, "b.1\n", 4);
	//malloc de buf
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (NULL);
	write (1, "b.2\n", 4);
	//initialisation de buf
	read_ret = read(rdr->fd, buf, BUFF_SIZE);
	write (1, "b.3\n", 4);
	ft_putnbr(read_ret);
	//si le read est bien passe
	if (read_ret > 0)
	{
		write (1, "b.4\n", 4);
		// si il n'y a pas de fin de ligne (eoln)
		if (!(eoln = ft_strchr(buf, '\n')))
		{
			write (1, "b.5\n", 4);
			//alors concatenner le buf du read suivant
			if (!(buf = ft_strjoin(buf, ft_bufjoin(rdr))))
			{
				write (1, "b.6\n", 4);
				return (NULL);
			}
		}
		//s'il y a un \n
		else
		{
			write (1, "b.7\n", 4);
			//mettre le reader sur eoln
			rdr->start = eoln + 1;
			//definir buf sans la suite du \n
			buf = ft_strsub(buf, 0, eoln - buf);
		}
	}
	//si le read a echoue
	else
	{
		write (1, "b.8\n", 4);
		return (NULL);
	}
	write (1, "b.9\n", 4);
	return (buf);
}

t_reader	*ft_getreader(int fd, t_list *rdr_lst)
{
//	write (1, "a.1\n", 4);
	if (!(rdr_lst))
		return ((t_reader *)ft_lstnew(ft_rdrnew(fd), sizeof(t_reader))->content);
	while (((t_reader *)rdr_lst->content)->fd != fd)
	{
//		write (1, "a.1.1\n", 6);
		//si le fd n'existe pas encore, il est ajoute a rdr_lst
		if ((rdr_lst = rdr_lst->next) == NULL)
		{
			rdr_lst = ft_lstnew(ft_rdrnew(fd), sizeof(t_reader));
		}
	}
//	write (1, "a.2\n", 4);
	return ((t_reader *)rdr_lst->content);
}



// fonction appelee en boucle pour lire chaque ligne une a une
int		get_next_line(int const fd, char **line)
{
	static t_list	*rdr_lst;
	t_reader 		*rdr;
	char			*buf;

	if (line)
	{
		write (1, "a\n", 2);
		if (!(rdr = ft_getreader(fd, rdr_lst)))
			return (-1);
		write (1, "b\n", 2);
		ft_putnbr(rdr->fd);
		if (!(buf = ft_bufjoin(rdr)))
			return (-1);
		write (1, "c\n", 2);
		return (1);
		*line = buf;
	}
	return (-1);
}
