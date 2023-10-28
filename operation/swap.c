/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:41:59 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/28 21:01:14 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	ft_printf("-- swap %s ---\n", stack->name);
	print_stack(stack);
	printf("bottom->prev:%d\n",stack->bottom->prev->value);
	printf("bottom->next:%d\n",stack->bottom->next->value);
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
	thrd->prev = top;
	stack->top = next;
	stack->bottom->next = next;
	// stack->bottom->prev = next;
	ft_printf("-- swaped %s ---\n", stack->name);
	print_stack(stack);
	printf("bottom->prev:%d\n",stack->bottom->prev->value);
	printf("bottom->next:%d\n",stack->bottom->next->value);
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("sb\n");
}
