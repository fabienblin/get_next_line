/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 18:03:03 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 16:54:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
# include "libft.h"
#include <fcntl.h>

int main (int argc, char ** argv)
{
	if (argc < 2)
		ft_exit("usage: get_next_line source_file [...]");
		
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	/*
	if (fd == -1)
		ft_exit("crash while opening file (maybe file name is wrong).");
	*/
	char *line = NULL;
	int gnl = 0;
	//char *keyboard = NULL;
	/*
	while ((gnl = get_next_line(fd1, &line)) == 1)// && read(0, keyboard, 1))
	{
		ft_putendl(line);
	}
	*/
	gnl = get_next_line(fd1, &line);
	ft_putendl(line);
	line = NULL;
	gnl = get_next_line(fd2, &line);
	ft_putendl(line);
	line = NULL;
	gnl = get_next_line(fd1, &line);
	ft_putendl(line);
	line = NULL;
	gnl = get_next_line(fd2, &line);
	ft_putendl(line);
	line = NULL;
	if (gnl == 0)
		ft_exit("EOF");
	else if (gnl == -1)
		ft_exit("An error occured while reading file.");
	return 0;
}