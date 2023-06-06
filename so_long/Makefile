# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pendejoo <pendejoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 15:04:12 by rvan-den          #+#    #+#              #
#    Updated: 2023/06/06 20:24:36 by pendejoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################
NAME	:= so_long
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror -g3

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SO_LONG			:=		mandatory/so_long.c \
						mandatory/so_long_utils.c \
						mandatory/so_long_utils_2.c \
						mandatory/so_long_map_check.c \
						mandatory/so_long_map_init.c \
						mandatory/so_long_moves.c \
						mandatory/so_long_move_utils.c \
						mandatory/test_mlx.c \
						
GNL				:=		gnl/get_next_line_utils.c \
						gnl/get_next_line.c \
					
UTILS			:=		utils/ft_isascii.c \
						utils/ft_strlen.c \
						utils/ft_split.c \
						utils/ft_strchr.c \
						utils/ft_strncmp.c \
						utils/ft_strtrim.c \
						utils/ft_substr.c \
						utils/err_utils.c \
						utils/ft_strdup.c \
						utils/ft_strlcpy.c \

UTILS_OBJS = $(UTILS:.c=.o)

GNL_OBJS	= $(GNL:.c=.o)

SO_LONG_OBJS = $(SO_LONG:.c=.o)

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

${NAME}:	${GNL_OBJS} ${SO_LONG_OBJS} ${UTILS_OBJS} 
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} ${SO_LONG_OBJS} ${UTILS_OBJS} ${GNL_OBJS} -o ${NAME} MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/rvan-den/.brew/opt/glfw/lib/"
			@echo "$(GREEN)$(NAME) created[0m ✔️"

debug:		${GNL_OBJS} ${SO_LONG_OBJS} ${UTILS_OBJS} 
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} -fsanitize=address ${FLAGS} ${SO_LONG_OBJS} ${UTILS_OBJS} ${GNL_OBJS} -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

linux:		${GNL_OBJS} ${SO_LONG_OBJS} ${UTILS_OBJS} 
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} ${SO_LONG_OBJS} ${UTILS_OBJS} ${GNL_OBJS} -o ${NAME} MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
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
