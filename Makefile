SRCS	= main.c print.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS += -Wall -Wextra -Werror
NAME	= minipow

all:		$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) -lssl -lcrypto

fclean:		clean
	rm -f $(NAME)
clean:
	rm $(OBJS)
re:			fclean all
