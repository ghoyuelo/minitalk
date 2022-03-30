# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:11:42 by ghoyuelo          #+#    #+#              #
#    Updated: 2022/02/17 13:57:28 by ghoyuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
SERVER_SRCS = server.c\
			  utils.c
SERVER_BONUS = server_bonus
SERVER_BONUS_SRCS = server_bonus.c\
					utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

CLIENT = client
CLIENT_SRCS = client.c\
			  utils.c
CLIENT_BONUS = client_bonus
CLIENT_BONUS_SRCS = client_bonus.c\
					utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

INCS = minitalk.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_SRCS) $(INCS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT)

$(SERVER): $(SERVER_SRCS) $(INCS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_SRCS) $(INCS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_SRCS) $(INCS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) -o $(CLIENT_BONUS)

clean:
	$(RM) $(SERVER_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
