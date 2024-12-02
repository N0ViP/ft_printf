CC = cc
FLAGS = -Wall -Wextra -Werror -g
FILES = ft_fill_with_padding.c	ft_max_min_abs.c	ft_printf.c	ft_putchar.c	ft_putint.c	\
		ft_putstr.c	ft_strlen.c	ft_length_of_numbers.c	ft_memset.c	ft_puthex.c	ft_putptr.c	\
		ft_putuint.c	ft_atoi.c	ft_strchr.c
OBJS = ${FILES:.c=.o}
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : all

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
