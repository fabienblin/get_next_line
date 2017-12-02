make -C ./rendu/libft/
gcc -ggdb -Wall -Wextra -Werror ./main.c rendu/get_next_line.c -I rendu/ -I rendu/libft/inc rendu/libft/libft.a -o ./test_gnl
lldb ./test_gnl $1 $2 
