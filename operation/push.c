/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:11:10 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/29 00:11:00 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node	*new;

	// printf("--- push %d to %c ---\n", value, stack->id);

	new = (t_node *)malloc(sizeof(t_node));
	new->value = value;
	new->next = stack->top;
	new->prev = stack->bottom;
	new->ordinal = -1;
	if (stack->size == 0)
	{
		new->next = new;
		new->prev = new;
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->next = stack->top;
		new->prev = stack->bottom;
		stack->top->prev = new;
		stack->bottom->next = new;
		stack->top = new;
	}
	stack->size++;
}

/**
* Take the first element at the top of B and put it at the top of A.
* Do nothing if B is empty.
* @param[out] a stack of a
* @param[out] b stack of b
* @return void 
*/
void	pa(t_stack *a, t_stack *b)
{
	if (b->size < 1)
		return ;
	push(a, pop(b));
	ft_printf("pa\n");
}

/**
* Take the first element at the top of A and put it at the top of B.
* Do nothing if A is empty.
* @param[out] a stack of a
* @param[out] b stack of b
* @return void 
*/
void	pb(t_stack *a, t_stack *b)
{
	if (a->size < 1)
		return ;
	push(b, pop(a));
	ft_printf("pb\n");
}
