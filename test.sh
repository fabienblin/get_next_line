make -C ./rendu/libft/
gcc -Wall -Wextra -Werror ./main.c rendu/get_next_line.c ./rendu/libft/src/*.c -I rendu/ -I rendu/libft/inc rendu/libft/libft.a -o ./test_gnl
./test_gnl $1 $2 
