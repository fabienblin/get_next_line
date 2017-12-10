make re -C ./libft/

gcc -ggdb ./main.c ./get_next_line.c ./libft/*.c -I ./ -I ./libft/includes ./libft/libft.a -o ./test_gnl
lldb ./test_gnl $1 $2 
