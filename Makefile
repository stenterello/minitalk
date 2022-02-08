SERVNAME=server
CLIENTNAME=client
CC=gcc
FLAGS=-Wall -Werror -Wextra
LIBFT=./includes/libft/libft.a

all: $(SERVNAME) $(CLIENTNAME)

$(SERVNAME): $(LIBFT)
	$(CC) $(FLAGS) src/server.c src/utils.c $(LIBFT) -o $(SERVNAME)

$(CLIENTNAME): $(LIBFT)
	$(CC) $(FLAGS) src/client.c src/utils.c $(LIBFT) -o $(CLIENTNAME)

$(LIBFT):
	$(MAKE) bonus -C includes/libft

fclean:
	rm -f $(SERVNAME) $(CLIENTNAME)

re: fclean all
