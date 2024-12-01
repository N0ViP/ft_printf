CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c	ft_puthex.c	ft_putptr.c	ft_putuint.c	ft_strlen.c	\
	ft_putchar.c	ft_putint.c	ft_putstr.c	ft_strchr.c
NAME = libftprintf.a
OBJS = $(FILES:.c=.o)

all = $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
