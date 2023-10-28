/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:28:14 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/28 20:22:05 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	ft_printf("-- reverse_rotate %s --\n",stack->name);
	print_stack(stack);
	printf("bottom:%d\n",stack->bottom->value);
	printf("bottom->prev:%d\n",stack->bottom->prev->value);
	printf("bottom->next:%d\n",stack->bottom->next->value);
	stack->bottom = stack->bottom->prev;
	printf("bottom->next:%d\n",stack->bottom->next->value);
	stack->top = stack->bottom->next;
	print_stack(stack);
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}