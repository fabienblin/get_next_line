make -C ./rendu/libft/ && gcc -Wall -Wextra -Werror ./main.c rendu/get_next_line.c -I rendu/ -I rendu/libft/includes rendu/libft/libft.a -o ./test_gnl && ./test_gnl rendu/Makefile | cat -e
