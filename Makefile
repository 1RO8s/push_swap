.PHONY: all debug analyze clean fclean re

NAME :=push_swap
CC := cc
OBJS	= $(SRCS:.c=.o)
INCLUDE := headers

# コンパイル対象ファイル
SRCS = \
push_swap.c\
operation/stack.c\
operation/swap.c\
operation/push.c\
operation/rotate.c\
operation/reverse_rotate.c\
sort/sort.c\
debug.c\

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME) ./libft/libft.a

%.o: %.c
	$(CC) ${CFLAGS} -I${INCLUDE} -c $< -o $@


all:CFLAGS=-Wall -Wextra -Werror
all:${NAME}

debug:CFLAGS=-g -fsanitize=address
debug:${NAME}

clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f ${NAME}
re: fclean all
# 静的解析
analyze:
	rm -f *.plist
	cc --analyze ${SRCS}
