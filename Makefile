NAME = push_swap

LIB = libpushswap.a
LIBFTPRINTF = ft_printf/libftprintf.a
LIBFT = ft_printf/libft/libft.a

#All previous libraries grouped into one
LIBS = $(LIB) $(LIBFTPRINTF) $(LIBFT)

SRCS = push_swap.c find_dups.c swap.c push.c rotate.c reverse_rotate.c \
	   number_sort.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

# make option to compile ft_printf folder
FT_PRINTF_PATH = -C ft_printf

all: sub_ft_printf $(NAME)

sub_ft_printf:
	$(MAKE) $(FT_PRINTF_PATH)

$(NAME): $(OBJS)
	ar rc $(LIB) $^
	$(CC) $(CFLAGS) $(LIBS) -o $@

clean:
	$(MAKE) $@ $(FT_PRINTF_PATH)
	rm -f $(OBJS) $(LIB)

fclean: clean
	$(MAKE) $@ $(FT_PRINTF_PATH)
	rm -f $(NAME)

re: fclean all
