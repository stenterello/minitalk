SERVNAME=server
CLIENTNAME=client
FLS=server.c \
	client.c \
	utils.c
SRC=$(addprefix src/, $(FLS))
OBJS=$(SRC:.c=.o)
CC=gcc
FLAGS=-Wall -Werror -Wextra
LIBFT=./includes/libft/libft.a

all: $(OBJS) $(SERVNAME) $(CLIENTNAME)

$(SERVNAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) src/server.o src/utils.o $(LIBFT) -o $(SERVNAME)

$(CLIENTNAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) src/client.o src/utils.o $(LIBFT) -o $(CLIENTNAME)

#$(OBJS): $(LIBFT)
#	$(CC) $(FLAGS) -c $(SRC)
#	mv *.o src/

$(LIBFT):
	$(MAKE) bonus -C includes/libft

clean:
	$(MAKE) fclean -C ./includes/libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVNAME) $(CLIENTNAME)

re: fclean all
