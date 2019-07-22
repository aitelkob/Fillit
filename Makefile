# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sberrich <sberrich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 03:30:46 by yait-el-          #+#    #+#              #
#    Updated: 2019/07/21 10:05:21 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = src/main.c
SRC += src/checker.c src/backtracking.c src/drag.c src/ft_exit.c src/ft_print_solution.c src/map_holder.c src/solver.c

all: $(NAME)
$(NAME):
		@make -C libft 
		@echo "make libft"
		@echo "make src"
		@echo "\033[92mdone!\033[0m"
		$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
clean:
		@echo "cleaning..."
		@make clean -C ./libft --no-print-directory
		@echo "libft object files removed!"
		@echo "\033[92mdone!\033[0m"
fclean: clean 
		@rm -f $(NAME)
		@echo "fillit executable removed!"
		@make fclean -C ./libft --no-print-directory
		@echo "\033[92mdone!\033[0m"
		
re: fclean all
norme:
		norminette $(SRC)
		norminette *.h
