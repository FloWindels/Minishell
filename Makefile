##
## EPITECH PROJECT, 2024
## makefile printf
## File description:
## makfile
##

SRC	=	src/main.c	\
		src/execute_command.c	\
		src/execute_cd.c	\
		src/print_error.c	\
		src/do_pipe.c	\

SRC_TEST	=	BS_minishell.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -L./lib/my -lmy -g

TESTFLAGS = ./tests/test_setting_up.c --coverage -lcriterion

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests
	make fclean -C ./lib/my/
	rm -f libmy.a

run: all
	./$(NAME)

tests_run:
	gcc -o unit_tests $(SRC_TEST) $(TESTFLAGS) $(CFLAGS)
	./unit_tests

re: fclean all
