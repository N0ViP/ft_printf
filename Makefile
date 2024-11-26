CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
FILES = ft_alloc_and_fill.c	ft_max.c	ft_putHex.c	ft_putstr.c	ft_substr.c				\
	ft_alloc.c	ft_numlen.c	ft_putchar.c	ft_putint.c	ft_putuint.c					\
	ft_hexlen.c	ft_printf.c	ft_puthex.c	ft_putptr.c	ft_strlen.c	ft_strchr.c	ft_atoi.c
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