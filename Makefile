# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parmando <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 13:37:38 by parmando          #+#    #+#              #
#    Updated: 2024/07/26 14:10:05 by parmando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME):  client server

client: client.o
	@$(CC) $(CFLAGS) client.o -o client

server: server.o
	@$(CC) $(CFLAGS) server.o -o server

%.o: %.c

	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f server client

re: fclean all

.PHONY: all clean fclean re
