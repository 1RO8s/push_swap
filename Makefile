.PHONY: all debug analyze clean fclean re bonus
.DEFAULT_GOAL := all

NAME := push_swap
CHCKER := mychecker
CC := cc
INCLUDE := headers

# コンパイル対象ファイル
COMMON_SRCS = \
arg_check.c\
compression.c\
operation/stack.c\
operation/swap.c\
operation/push.c\
operation/rotate.c\
operation/reverse_rotate.c\
sort/calc_cost.c\
sort/rotate_stack.c\
sort/sort.c\
sort/turk_sort.c\
sort/utils.c\
# debug.c\
# test/test_swap.c\

SRCS_MANDATORY = $(COMMON_SRCS) push_swap.c
SRCS_BONUS = $(COMMON_SRCS) bonus.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS_MANDATORY)
	$(MAKE) -C ./libft
	$(CC) ${CFLAGS} $(OBJS_MANDATORY) -o $(NAME) ./libft/libft.a

$(CHCKER): $(OBJS_BONUS)
	$(MAKE) -C ./libft
	$(CC) ${CFLAGS} $(OBJS_BONUS) -o $(CHCKER) ./libft/libft.a

%.o: %.c
	$(CC) ${CFLAGS} -I${INCLUDE} -c $< -o $@

all:SRCS=$(SRCS_MANDATORY)
all:CFLAGS=-Wall -Wextra -Werror
all:${NAME}

bonus:SRCS=$(SRCS_BONUS)
bonus:CFLAGS=-Wall -Wextra -Werror
bonus:${CHCKER}

debug:CFLAGS=-g -fsanitize=address
debug:${NAME}

clean: 
	rm -f $(SRCS_MANDATORY:.c=.o) $(SRCS_BONUS:.c=.o)
fclean: clean
	rm -f ${NAME} ${CHCKER}
re: fclean all
# 静的解析
analyze:
	rm -f *.plist
	cc --analyze ${SRCS}
