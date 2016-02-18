#include <stdio.h>
#include <fcntl.h>
#include "../rendu/get_next_line.h"

int main () 
{
	char *line;

	int fd1 = open("file", O_RDONLY);
	while(get_next_line(fd1, &line) == 1)
	{
		ft_putendl(line);
	}
printf(":::::::::::::::::::\n");	
	int fd2 = open("file2", O_RDONLY);
	while(get_next_line(fd2, &line) == 1)
	{
		ft_putendl(line);
	}
	return 0;
}
