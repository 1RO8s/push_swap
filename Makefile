.PHONY: all debug analyze clean fclean re bonus
.DEFALUT_GOAL := all

NAME := push_swap
CHCKER := mychecker
CC := cc
OBJS	= $(SRCS:.c=.o)
INCLUDE := headers

# コンパイル対象ファイル
SRCS = \
push_swap.c\
arg_check.c\
compression.c\
operation/stack.c\
operation/swap.c\
operation/push.c\
operation/rotate.c\
operation/reverse_rotate.c\
sort/rotate_stack.c\
sort/sort.c\
sort/turk_sort.c\
sort/utils.c\
debug.c\
# test/test_swap.c\

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME) ./libft/libft.a

$(CHCKER): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) ${CFLAGS} $(OBJS) -o $(CHCKER) ./libft/libft.a

%.o: %.c
	$(CC) ${CFLAGS} -I${INCLUDE} -c $< -o $@


all:CFLAGS=-Wall -Wextra -Werror
all:${NAME}

bonus:${CHCKER}

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
