INC		=	../rendu/libft/includes/

LIBFT	=	../rendu/libft/

GNL		=	../rendu/

all :	main.c ../rendu/get_next_line.[ch] ../rendu/libft/libft.[ah]
	gcc -Wall -Wextra -Werror main.c ../rendu/get_next_line.[ch] ../rendu/libft/libft.[ah] -I../rendu/libft

test :
	make re -C ../rendu/libft
	gcc -o $(GNL)get_next_line.o -c $(GNL)get_next_line.c -I $(INC)
	gcc -o main.o -c main.c -I $(INC)
	gcc main.o $(GNL)get_next_line.o -I $(INC)

test2 :
	make -C ../rendu/libft
	gcc -o $(GNL)gnl.o -c $(GNL)gnl.c -I $(INC)
	gcc -o main.o -c main.c -I $(INC) -I $(GNL)
	gcc main.o $(GNL)gnl.o -I $(INC)  -L ../rendu/libft/ -lft
