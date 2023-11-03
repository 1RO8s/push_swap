/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 07:59:50 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/04 01:07:25 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1000
# define TRUE 1
# define FALSE 0

// # define malloc(size) my_malloc(size)
// # define free(size) my_free(size)

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				ordinal;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	char			id;
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

// arg_check.c
int					*argvtoi(int argc, char *argv[]);

// stack.c
t_stack				*create_stack(char id, int *values, int values_count);
int					*get_values(t_stack *stack);
int					pop(t_stack *stack);

// swap.c
void				swap(t_stack *stack, int print_flg);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

// push.c
void				push(t_stack *stack, int value);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

// rotate.c
void				rotate(t_stack *stack, int print_flg);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

// reverse_rotate.c
void				reverse_rotate(t_stack *stack, int print_flg);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// compression.c
void				compression(t_stack *stack);
void				set_order(t_stack *stack);

// sort.c
void				sort2(t_stack *a);
void				sort3(t_stack *a);
void				sort4(t_stack *a, t_stack *b);
void				sort5(t_stack *a, t_stack *b);
void				sort6(t_stack *a, t_stack *b);

// turk_sort.c
void				operation_a(t_stack *a, int op_cnt);
void				operation_b(t_stack *b, int op_cnt);
int					max_of(t_stack *stack);
int					min_of(t_stack *stack);
void				turk_sort(t_stack *a, t_stack *b);
int					get_total_cost(int cost_a, int cost_b);

// libft
int					ft_atoi(const char *str);
int					ft_printf(const char *format, ...);
size_t				ft_strlen(const char *s);
int					is_space(char c);

// debug
void				print_stack(t_stack *stack);
void				print_stack_values(t_stack *stack);
void				print_node(t_node *node);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

// test
int					test_swap(int argc, char *argv[]);

#endif
