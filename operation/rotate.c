/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:28:14 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/03 01:38:13 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, int print_flg)
{
	stack->top = stack->top->next;
	stack->bottom = stack->top->prev;
	if (print_flg == 1 && stack->id == 'A')
		ft_printf("ra\n");
	if (print_flg == 1 && stack->id == 'B')
		ft_printf("rb\n");
}

void	ra(t_stack *a)
{
	rotate(a, 1);
}

void	rb(t_stack *b)
{
	rotate(b, 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}
