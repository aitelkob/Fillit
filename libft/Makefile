# **************************************************************************** #
#  #
#  :::  :::::::: #
# Makefile   :+:  :+: :+: #
#  +:+ +:+  +:+  #
# By: sberrich <marvin@42.fr> +#+  +:+ +#+  #
#  +#+#+#+#+#+ +#+ #
# Created: 2019/04/02 14:17:53 by sberrich  #+# #+# #
# Updated: 2019/05/23 17:17:57 by sberrich  ### ########.fr #
#  #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c ft_strdel.c ft_strlcat.c ft_strncpy.c ft_strstr.c\
	  ft_atoi.c ft_isprint.c ft_memcpy.c ft_putendl.c ft_strcat.c ft_strdup.c ft_strlen.c ft_strnequ.c ft_strsub.c\
	  ft_bzero.c  ft_itoa.c ft_memdel.c ft_putendl_fd.c ft_strchr.c ft_strequ.c ft_strmap.c ft_strnew.c ft_strtrim.c\
	  ft_isalnum.c ft_memalloc.c ft_memmove.c ft_putnbr.c ft_strclr.c ft_striter.c ft_strmapi.c ft_strnstr.c ft_tolower.c\
	  ft_isalpha.c ft_memccpy.c ft_memset.c ft_putnbr_fd.c  ft_strcmp.c ft_striteri.c ft_strncat.c ft_strrchr.c ft_toupper.c\
	  ft_isascii.c ft_memchr.c ft_putchar.c ft_putstr.c ft_strcpy.c ft_strjoin.c ft_strncmp.c ft_strsplit.c\

OBJECTS = $(SRC:%.c=%.o)
	

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc libft.a $(OBJECTS)
	@echo -e "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f libft.a
re: fclean all
