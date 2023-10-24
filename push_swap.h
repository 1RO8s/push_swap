/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 07:59:50 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/25 04:48:52 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1000
# define TRUE 1
# define FALSE 0

// # define malloc(size) my_malloc(size)
// # define free(size) my_free(size)

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
	char			*name;
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

t_stack				*create_stack(char *_name);
int					pop(t_stack *stack);

// swap.c
void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sa(t_stack *a);

// push.c
void				push(t_stack *stack, int value);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

// rotate.c
void				rotate(t_stack *stack);
// reverse_rotate.c
void				reverse_rotate(t_stack *stack);

// debug
void				print_stack(t_stack *stack);
void				print_stack_values(t_stack *stack);
void				print_node(t_node *node);

#endif
