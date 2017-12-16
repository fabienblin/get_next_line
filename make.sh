cd rendu2
norminette
#compilation moulinette
make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o ../main.o -c ../main.c
clang -o test_gnl ../main.o get_next_line.o -I libft/includes -L libft/ -lft
make fclean -C libft/
rm get_next_line.o
./test_gnl ../test2
./test_gnl auteur
./test_gnl get_next_line.c
./test_gnl get_next_line.h
./test_gnl ../main.o
rm test_gnl