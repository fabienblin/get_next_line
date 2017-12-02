/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fblin <fblin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/01/08 14:03:37 by fblin        #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:50:47 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
/*
** RIP David Bowie 08/01/1947 - 10/01/2016
*/
#include "get_next_line.h"
#include "libft.h"

static t_reader		*ft_rdrnew(int fd)
{
	t_reader *rdr;

	if (!(rdr = (t_reader *)malloc(sizeof(t_reader))))
		return (NULL);
	rdr->fd = fd;
	rdr->start = NULL;
	return (rdr);
}

static int				ft_getline(t_reader *rdr, char **line)
{
	int		read_size;
	char	*eol;
	char	*buf;

	//si il n'y a pas de \n dans buf alors il faut encore lire
	//si il y a un \n dans buf alors arreter de lire
	eol = NULL;
	if (rdr->start)
	{
		ft_realloc((void **)line, ft_strlen(rdr->start));
		ft_strcpy(*line, rdr->start);
	}
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((read_size = read(rdr->fd, buf, BUFF_SIZE)) > 0 && !eol)
	{
		if ((eol = ft_strchr(buf, '\n')))
		{
			*line = ft_strjoin(*line, ft_strsub(buf, 0, eol - buf));
			//ft_realloc((void **)line, ft_strlen(*line) + eol - buf);
			//ft_strncpy(*line, buf, buf - eol);
			rdr->start = ft_strsub(buf, eol - buf + 1, ft_strlen(eol + 1));
		}
		else
			*line = ft_strjoin(*line, ft_strsub(buf, 0, eol - buf));
	}
	return (read_size <= 0 ? read_size : 1);
}

static t_reader	*ft_getreader(int fd, t_list **rdr_lst)
{
	t_list		*lst;
	
	lst = *rdr_lst;
	while (lst)
	{
		if (((t_reader *)lst->content)->fd == fd)
			return ((t_reader *)lst->content);
		lst = lst->next;
	}
	if (!lst)
	{
		lst = ft_lstnew(ft_rdrnew(fd), sizeof(t_reader));
		ft_lstadd(rdr_lst, lst);
	}
	return ((t_reader *)lst->content);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*rdr_lst = NULL;
	t_reader		*rdr;

	if (fd < 0 || fd > 256 || line == NULL)
		return (-1);
	if (!(rdr = ft_getreader(fd, &rdr_lst)))
		return (-1);
	return (ft_getline(rdr, line));
}
