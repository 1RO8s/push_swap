/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:41:59 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/03 01:38:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int print_flg)
{
	t_node	*top;
	t_node	*next;
	t_node	*thrd;

	// ft_printf("-- swap %c ---\n", stack->id);
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
	if (print_flg == 1 && stack->id == 'A')
		ft_printf("sa\n");
	if (print_flg == 1 && stack->id == 'B')
		ft_printf("sb\n");
}

void	sa(t_stack *a)
{
	swap(a, 1);
	ft_printf("sa!!\n");
}

void	sb(t_stack *b)
{
	swap(b, 1);
	ft_printf("sb!!\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("sb\n");
}
