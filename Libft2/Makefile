# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:03:53 by rvan-den          #+#    #+#              #
#    Updated: 2022/11/21 17:07:19 by rvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOURS_GREEN = '\033[0;32m'

COLOURS_RED = '\033[0;31m'

COLOURS_YELLOW = '\033[0;33m' 

COLOUR_END = '\033[0m'

NAME = libft.a

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror
## Strings

SRC 		=	ft_strlcpy.c \
				ft_memcpy.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memmove.c \
				ft_memset.c \
				ft_bzero.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

MY_OBJECTS = $(SRC:.c=.o)



RM = rm -rf

all : libft.a

$(NAME): $(MY_OBJECTS)
			@ar rcs $(NAME) $(MY_OBJECTS)
			@echo '\033[0;32mCompilation OK ✅ ';
			@$(OK_MSG): $(NAME) 

fclean : clean
			@$(RM) $(NAME)
			@$(EXECDEL_MSG) : fclean
			@echo '\033[0;31mLibft.a deleted ⭕️';

clean :
			@$(RM) $(MY_OBJECTS)
			@$(OBJ_MSG) : clean
			@echo '\033[0;31mObjects files deleted ❌';

re : fclean all

.PHONY:		all clean fclean re
