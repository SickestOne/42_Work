################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      data_parser.c \
                          ft_long_atoi.c \
                          ft_split.c \
                          ft_strlen.c \
                          lsts_utils.c \
                          lsts_utils_p2.c \
                          lsts_utils_p3.c \
                          lsts_utils_p4.c \
                          lsts_utils_p5.c \
                          pa.c \
                          parser_utils.c \
                          pb.c \
                          push_swap.c \
                          ra_rb_rr.c \
                          rra.c \
                          rrb.c \
                          sa_sb_ss.c \
                          sort_big.c \
                          sort_big_utils.c \
						  sort_big_utils_2.c \
                          sort_checker.c \
                          sort_for_five.c \
                          sort_for_five_utils.c \
                          start_sort.c \
						  free_all.c \
						  fill_b_utils.c \
                          
OBJS        := $(SRCS:.c=.o)

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

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
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


