/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:41:59 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/05 03:03:01 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*top;
	t_node	*next;
	t_node	*thrd;

	top = stack->top;
	next = stack->top->next;
	if (stack->size <= 2)
	{
		top->next = next;
		next->prev = top;
		stack->top = next;
		stack->bottom = top;
	}
	else if (stack->size >= 3)
	{
		thrd = stack->top->next->next;
		top->next = next->next;
		next->prev = stack->bottom;
		thrd->prev = top;
		stack->bottom->next = next;
	}
	top->prev = next;
	next->next = top;
	stack->top = next;
}

void	swap(t_stack *stack, int print_flg)
{
	ft_swap(stack);
	if (print_flg == 1 && stack->id == 'A')
		ft_printf("sa\n");
	if (print_flg == 1 && stack->id == 'B')
		ft_printf("sb\n");
}

void	sa(t_stack *a)
{
	swap(a, 1);
}

void	sb(t_stack *b)
{
	swap(b, 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}
