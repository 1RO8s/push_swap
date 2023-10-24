/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:28:14 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/25 04:00:03 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*top;
	t_node	*next;
	t_node	*thrd;

	top = stack->top;
	next = stack->top->next;
	thrd = stack->top->next->next;
	top->next = next->next;
	top->prev = next;
	next->next = top;
	next->prev = stack->bottom;
	thrd->prev = next;
	stack->top = next;
	stack->bottom->next = next;
}

void	rotate(t_stack *stack)
{
	stack->top = stack->top->next;
	stack->bottom = stack->top->prev;
}

void	reverse_rotate(t_stack *stack)
{
	stack->bottom = stack->bottom->prev;
	stack->top = stack->bottom->next;
}
