# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/28 17:52:33 by fablin       #+#   ##    ##    #+#        #
#    Updated: 2017/11/28 21:01:22 by fablin      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	=	get_next_line

CFILES	=	get_next_line.c main.c

OFILES	=	$(CFILES:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

INC		=	./

LIBFT	=	./libft/libft.a

LIB_INC	=	./libft/includes/

all		:
			 clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
			 clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
			 clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

$(NAME)	:
			make -C ./libft/
			gcc $(FLAGS) -c $(CFILES) -I $(INC) -I $(LIB_INC)

clean	:
			make clean -C ./libft/
			rm -rf $(OFILES)

fclean	:	clean
			make fclean -C ./libft/
			rm -rf $(NAME)

re		:	fclean all
			make re -C ./libft/
