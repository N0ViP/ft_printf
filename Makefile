CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
FILES = ft_alloc_and_fill.c	ft_putHex.c	ft_putstr.c	ft_substr.c	ft_atoi.c	ft_strchr.c	\
	ft_alloc.c	ft_numlen.c	ft_putchar.c	ft_putint.c	ft_putuint.c	ft_hexlen_ptr.c	\
	ft_unumlen.c	ft_printf.c	ft_puthex.c	ft_putptr.c	ft_strlen.c	ft_abs.c	ft_max.c

OBJS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
