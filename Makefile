# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 13:37:47 by arthur            #+#    #+#              #
#    Updated: 2021/07/25 14:38:50 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROPERTY

NAME=pipex
FILE=$(wildcard exec/*.c) \
	 $(wildcard parsing/*.c) \
	 $(wildcard utils/*.c)
FLAGS=-Wall -Werror -Wextra
MAIN=main.c
CC=gcc

#RULES
################################################################################

lib:
	@cd libft && make > /dev/null
	@$(CC) $(FLAGS) $(FILE) -c
	@ar rcs lib$(NAME).a *.o
	@echo "Creating lib done"

lib_bonus:
	@cd libft && make > /dev/null
	@$(CC) $(FLAGS) -D BONUS=1 $(FILE) -c 
	@ar rcs lib$(NAME).a *.o
	@echo "Creating lib done"

all: lib 
	@$(CC) $(FLAGS) $(MAIN) -L. -l$(NAME) -Llibft -lft -o $(NAME)
	@echo "Build done"

clean:
	@cd libft && make clean > /dev/null
	@rm -rf *.o
	@echo "Cleaning done"
	
fclean: clean
	@cd libft && make fclean > /dev/null
	@rm -rf $(NAME)
	@rm -rf lib$(NAME).a
	@echo "Super cleaning done"

bonus: fclean lib_bonus
	@$(CC) $(FLAGS) $(MAIN) -L. -l$(NAME) -Llibft -lft -o $(NAME)
	@echo "Bonus build done"

re: fclean all
	@echo "Rebuild done"

.DEFAULT_GOAL:= all
