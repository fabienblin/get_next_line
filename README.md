# GNL *get next line*

Line by line file/pipe reader - Scholar project

This project adds a reading function to Libft. This allows multiple file descriptors at a time.

### Returns

While reading a line get_next_line() returns 1.

Returns 0 at EOF and closes.

If open or read fails with an error, get_next_line() returns -1 and closes.

### Example

main.c

```
#include "libft.h"

int main (int argc, char **argv)
{
  file = argv[1]
  char *line = NULL;
  int fd = open(file);
  while ((gnl = get_next_line(fd, &line)) > 0)
  {
    printf("%s", line);
  }
  if (gnl == -1)
    exit(0);
}
```

Compile and run:

This code prints itself to console.

```
make
gcc main.c -I ./libft/inc -L libft/libft.a -o gnl
./gnl main.c
```

## Author

* **Fabien Blin** @ Le-101
