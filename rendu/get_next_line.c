/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 18:25:57 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/10 19:14:00 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
/*
** RIP David Bowie 08/01/1947 - 10/01/2016
*/
#include "get_next_line.h"
/*
char		*ft_strndup(const char *s1, size_t n)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*str;
	int		nbr;
	char	*d;

	nbr = ft_strlen(s1) + ++len;
	str = ft_strnew(nbr);
	d = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - d));
}

static char		*ft_freejoin(char *tmp, char *buf, int ret)
{
	char	*l;

	l = tmp;
	tmp = ft_strnjoin(tmp, buf, ret);
	free(l);
	return (tmp);
}
*/
/*
** In this function after checking if the read asn't failed we first get into
** our linked list and we create the first node.
** The first while is looking of any \n and is joinning all that we've been
** (BUFF_SIZE)
** Second while : while the strings exist as a char * (cast from void*) we are
** looking for a \n , if we are able to find one we copy what we had before it
** with ft_strndup and we put it into our linked list.
** The Second if locates the \n and use ++ret so we can avoid it for the next
** step, we then use the variable l to temporary hold what is currently in
** list->content. Ad we use ft_strdup to alocate the memory for our current
** position in list->content based on the variable ret (++\n) and we free
** what's inside l from our memory.
** The ternary operator is used to return (1) at the end of a line and at the
** end of a file (\n or \0) and once we call gnl again he returns 0.
*/
#include <stdio.h>

void	printf_rdrlst(t_list *rdr_lst)
{
	t_list *lst = rdr_lst;
	printf("reader lst : \n");
	while(lst)
	{
		printf("tetri (fd=%d, prev='%s')\n",
		((t_reader *)lst->content)->fd,
		((t_reader *)lst->content)->prev);
		lst = lst->next;
	}
}

static t_reader	*ft_rdrnew(int fd)
{
	t_reader	*new;
	
	if (!(new = (t_reader *)malloc(sizeof(t_reader))))
		return (NULL);
	new->fd = fd;
	new->prev = NULL;
	return (new);
}

static t_reader	*ft_getreader(t_list **rdr_lst, int fd)
{
		t_reader	*rdr;
		t_list		*lst;

		lst = *rdr_lst;
		while (lst)
		{
			rdr = (t_reader *)lst->content;
			if (rdr->fd == fd)
				return (rdr);
			lst = lst->next;
		}
		if (!lst)
		{
			if (!(lst = ft_lstnew(NULL, 0)))
				return (NULL);
			if (!(rdr = ft_rdrnew(fd)))
				return (NULL);
			lst->content = rdr;
			ft_lstadd(rdr_lst, lst);
		}
		return (rdr);
}

char		*ft_strfreejoin(char *s1, char *s2)
{
	char *join;
	
	join = NULL;
	if (!s1)
		join = ft_strdup(s2);
	else if (!s2)
		join = ft_strdup(s1);
	else
		join = ft_strjoin(s1, s2);
	free(s1);
	return (join);
}

static int	get_line(t_reader *rdr, char **line)
{
	int		siz;
	char	*eol;
	char	buf[BUFF_SIZE + 1];
	
	(void)line;
	buf[BUFF_SIZE] = 0;
	siz = 0;
	eol = NULL;
	//stocker les buffers dans prev
	while(!(eol = ft_strchr(rdr->prev, '\n'))
	&& (siz = read(rdr->fd, buf, BUFF_SIZE)) > 0)
	{
		//printf("buf='%s'\n", buf);
		rdr->prev = ft_strfreejoin(rdr->prev, buf);
		ft_bzero(buf, siz);
	}
	
	if (eol)
	{
		//definir line
		*line = ft_strsub(rdr->prev, 0, eol - rdr->prev);
		//definir prev
		rdr->prev = ft_strdup(eol + 1);
	}
	else
	{
		*line = ft_strdup(rdr->prev);
		free(rdr->prev);
	}
	return (siz);
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*rdr_lst = NULL;
	int				gnl;
	t_reader		*rdr;
	char			*buf;
	
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	rdr = ft_getreader(&rdr_lst, fd);
	//printf_rdrlst(rdr_lst);
	gnl = get_line(rdr, line);
	return (gnl > 0 ? 1 : gnl);
}
