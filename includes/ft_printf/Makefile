LIBFT = ../libft/libft.a

NAME = libftprintf.a

SRCSFLS = ft_printf.c \
			ft_ispercent.c \
			ft_deep_elaborate.c \
			ft_deep_elaborate_utils.c \
			ft_treat_d.c \
			ft_treat_c.c \
			ft_treat_percent.c \
			ft_treat_s.c \
			ft_treat_u.c \
			ft_treat_ptr.c \
			ft_putnbr_base.c \
			ft_putnbr_u_base.c \
			ft_putnbr_u_fd.c \
			ft_puthex.c \
			ft_int_to_hex.c \
			ft_unbrlen.c \
			ft_utoa.c \
			ft_utils_s.c \
			ft_utils_d.c \
			ft_utils_ptr.c \
			ft_utils_u.c \
			ft_handlers_d.c \
			ft_handlers_u.c \
			ft_handlers_ptr.c \
			ft_treat_x.c \
			ft_utils_x.c \
			ft_utils_x_2.c \
			ft_handlers_x.c \
			ft_treat_long.c \
			ft_handlers_long.c \
			synthesis.c 

SRCS =  $(addprefix srcs/, $(SRCSFLS))

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)
OBJSD = $(addprefix objs/, $(OBJS))

$(NAME): $(OBJS)
	$(MAKE) bonus -C ../libft
	cp ../libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	mv *.o objs
	ar rcs $(NAME) objs/*.o

all: $(NAME)

bonus: all

clean:
	$(MAKE) clean -C ../libft
	rm -rf objs/*.o
	rm -rf srcs/*.o

fclean: clean
	$(MAKE) fclean -C ../libft
	rm -rf $(NAME)

re: fclean all
