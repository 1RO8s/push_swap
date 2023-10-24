NAME :=push_swap
CC := cc
CFLAGS = -Wall -Wextra -Werror
DEBUG := -g -fsanitize=address
OBJS	= $(SRCS:.c=.o)
INCLUDE := headers

# コンパイル対象ファイル
SRCS = \
push_swap.c\
stack.c\
operation.c\
push.c\
debug.c\

$(NAME): $(OBJS)
	# $(MAKE) -C ./libft
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
	# $(CC) ${CFLAGS} $(OBJS) -o $(NAME) ./libft/libft.a

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

.PHONY: all
all:CFLAGS=-Wall -Wextra -Werror
all:${NAME}

.PHONY: debug
debug:CFLAGS=$(DEBUG)
debug:${NAME}

# 静的解析
.PHONY: analyze
analyze:
	rm -f *.plist
	cc --analyze ${SRCS}

.PHONY: clean
clean: 
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f ${NAME}

.PHONY: re
re: fclean all