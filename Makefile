NAME	=	ft_ls

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

INCLUDE	=	include/fillit.h

SRCS	=	src/main.c

all: 		$(NAME)
			$(CC) -o $(NAME) $(OBJS) -I . -L./libft -lft

$(NAME): $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $< -I . $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
	make re -C libft/

.PHONY: all re clean fclean