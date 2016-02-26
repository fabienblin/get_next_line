#include <stdio.h>
#include <fcntl.h>
#include "../rendu/get_next_line.h"

int main () 
{
	char *line;

	int fd1 = open("file", O_RDONLY);
	line = NULL;
	while (get_next_line(fd1, &line) == 1)
	{
		printf("'%s'\n",line);
		free(line);
		line = NULL;
	}
	return 0;
}
