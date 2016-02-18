all :	main.c ../rendu/get_next_line.[ch] ../rendu/libft/libft.[ah]
	gcc -Wall -Wextra -Werror main.c ../rendu/get_next_line.[ch] ../rendu/libft/libft.[ah] -I../rendu/libft

test :	main.c ../rendu/get_next_line.[ch] ../rendu/libft/libft.[ah]
	make re -C ../rendu/libft/
	gcc main.c ../rendu/get_next_line.[ch] ../rendu/libft/libft.[ah] -I../rendu/libft
