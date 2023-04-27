# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-den <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 13:53:59 by rvan-den          #+#    #+#              #
#    Updated: 2023/04/27 13:50:43 by rvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = serv_src/ft_server.c \
		 serv_src/free_all.c \

CLIENT = client_src/ft_client.c \

PRINTF = printf_minitalk/ft_do_c.c \
		  printf_minitalk/ft_do_prct.c \
		  printf_minitalk/ft_do_s.c \
		  printf_minitalk/ft_printf.c \
		  printf_minitalk/ft_ptradress.c \
		  printf_minitalk/ft_puthex_maj.c \
		  printf_minitalk/ft_puthex_min.c \
		  printf_minitalk/ft_putnbr_fpf.c \

CC = @gcc 

FLAGS = -Wall -Werror -Wextra 

SERVER_NAME	=	server

CLIENT_NAME	=	client

PRINTF_SRC =	$(PRINTF)

PRINTF_OBJS =	$(PRINTF:.c=.o)

SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

all:  $(SERVER_NAME) $(CLIENT_NAME)

server: $(SERVER_OBJS) $(PRINTF_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) $(PRINTF_OBJS) -o $(SERVER_NAME)

client: $(CLIENT_OBJS) $(PRINTF_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) $(PRINTF_OBJS) -o $(CLIENT_NAME)

bonus: all

clean:
	@rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(PRINTF_OBJS)

fclean:	clean
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re : fclean all
