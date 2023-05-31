# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-den <rvan-den@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 10:02:00 by rvan-den          #+#    #+#              #
#    Updated: 2023/05/31 10:02:01 by rvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := pipex
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=     		srcs/pipex.c \
						srcs/pipex_utils.c \
						srcs/pipex_utils_p2.c \

UTILS       :=			utils/ft_strncmp.c \
						utils/ft_substr.c \
						utils/ft_strlen.c \
						utils/ft_strjoin.c \
						utils/ft_split.c \
						utils/ft_isascii.c \

BONUS 		:=          bonus/multi_pipes_bonus.c \
                          
OBJS        := $(SRCS:.c=.o)

UTILS_OBJS  := $(UTILS:.c=.o)

BNS_OBJS	:= $(BONUS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS} ${UTILS_OBJS} ${BNS_OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} ${OBJS} ${UTILS_OBJS} ${BNS_OBJS} -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


