# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:03:53 by rvan-den          #+#    #+#              #
#    Updated: 2022/12/19 13:13:28 by rvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOURS_GREEN = '\033[0;32m'

COLOURS_RED = '\033[0;31m'

COLOURS_YELLOW = '\033[0;33m' 

COLOUR_END = '\033[0m'

NAME = libftprintf.a

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror
## Strings

SRC 		=	ft_printf.c \
				ft_do_c.c \
				ft_do_s.c \
				ft_ptradress.c \
				ft_putnbr_fpf.c \
				ft_puthex_min.c \
				ft_puthex_maj.c

MY_OBJECTS = $(SRC:.c=.o)


RM = rm -rf

all : libftprintf.a

$(NAME): $(MY_OBJECTS)
			@ar rcs $(NAME) $(MY_OBJECTS)
			@echo '\033[0;32mCompilation OK ✅ ';
			@$(OK_MSG): $(NAME) 

fclean : clean
			@$(RM) $(NAME)
			@$(EXECDEL_MSG) : fclean
			@echo '\033[0;31mLibftprintf.a deleted ⭕️';

clean :
			@$(RM) $(MY_OBJECTS) ${BONUS_OBJS}
			@$(OBJ_MSG) : clean
			@echo '\033[0;31mObjects files deleted ❌';

re : fclean all

 ## bonus:	${MY_OBJECTS} ${BONUS_OBJS}
		 ## ar rcs ${NAME} ${MY_OBJECTS} ${BONUS_OBJS}


.PHONY:		all clean fclean re
