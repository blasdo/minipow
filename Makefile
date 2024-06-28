SRCS	= main.c print.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc -Wall -Wextra -Werror
NAME	= minipow

all:		$(OBJS)
	gcc $(OBJS) -o $(NAME) -l:libssl.a -lcrypto

fclean:		clean
	rm -f $(NAME)
clean:
	rm $(OBJS)
re:			fclean all
