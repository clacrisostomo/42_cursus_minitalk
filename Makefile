NAME = server
NAME2 = client

CC = clang
CFLAGS = -Werror -Wall -Wextra -g

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

INCLUDE = minitalk.h

all: $(NAME) $(NAME2) $(INCLUDE)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SERVER_OBJS)
	@echo "\nCompile SERVER.........................\033[32m[DONE]\033[0m"

$(NAME2): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME2) $(CLIENT_OBJS)
	@echo "Compile CLIENT.........................\033[32m[DONE]\033[0m\n"

git:
	@git add .
	@git commit -m "$m"
	@git push
#make git m="blablabla"

clean:
	@${RM} ${SERVER_OBJS}
	@${RM} ${CLIENT_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${NAME2}

re: fclean all

rebonus: fclean

.PHONY: all clean fclean re
