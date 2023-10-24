/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:41:59 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/25 04:44:03 by hnagasak         ###   ########.fr       */
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

void	sa(t_stack *a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	printf("sb\n");
}