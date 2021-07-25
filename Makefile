# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 14:37:45 by csantos-          #+#    #+#              #
#    Updated: 2021/07/25 16:43:49 by csantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME_SERVER = server
NAME_CLIENT = client

BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

CC = clang
CFLAGS = -Werror -Wall -Wextra
INCLUDE = ./include/minitalk.h
INCLUDE_BONUS = ./include/minitalk_bonus.h

SRC = ./mandatory/
SRC_BONUS = ./bonus/

SERVER = $(SRC)server.c
CLIENT = $(SRC)client.c

SERVER_OBJ = $(SERVER:.c=.o)
CLIENT_OBJ = $(CLIENT:.c=.o)

SERVER_BONUS = $(SRC_BONUS)server_bonus.c
CLIENT_BONUS = $(SRC_BONUS)client_bonus.c

SERVER_OBJ_BONUS = $(SERVER_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_BONUS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT) $(INCLUDE)

$(NAME_SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SERVER_OBJ)
	@echo "Compiling server.........................\033[32m[OK!]\033[0m\n"
	@echo "\033[32m Welcome to Minitalk!\033[0m\n"
	@echo "\033[34m Run ./server\033[0m\n"
	@echo "\033[34m Then run ./client in another terminal\033[0m\n"

$(NAME_CLIENT): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJ)
	@echo "Compiling client.........................\033[32m[OK!]\033[0m\n"

bonus: $(SERVER_BONUS) $(CLIENT_BONUS) $(INCLUDE_BONUS)

$(SERVER_BONUS): $(SERVER_OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(BONUS_SERVER) $(SERVER_OBJ_BONUS)
	@echo "Compiling Bonus server.........................\033[32m[OK!]\033[0m\n"
	@echo "\033[32m Welcome to Minitalk!\0330m\n"
	@echo "\033[34m Run ./server\033[0m\n"
	@echo "\033[34m Then run ./client in another terminal\033[0m\n"

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJ_BONUS)
	@echo "Compiling client.........................\033[32m[OK!]\033[0m\n"

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
