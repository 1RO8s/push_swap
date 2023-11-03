/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:28:14 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/04 00:31:41 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, int print_flg)
{
	stack->bottom = stack->bottom->prev;
	stack->top = stack->bottom->next;
	if (print_flg == 1 && stack->id == 'A')
		ft_printf("rra\n");
	if (print_flg == 1 && stack->id == 'B')
		ft_printf("rrb\n");
}

void	rra(t_stack *a)
{
	reverse_rotate(a, 1);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b, 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_printf("rrr\n");
}
