/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:29:35 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 03:29:48 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_rotate_b(t_stack *b, int op_cnt)
{
	if (op_cnt > 0)
	{
		while (op_cnt > 0)
		{
			rb(b);
			op_cnt--;
		}
	}
	else
	{
		while (op_cnt < 0)
		{
			rrb(b);
			op_cnt++;
		}
	}
}

void	exe_rotate_a(t_stack *a, int op_cnt)
{
	if (op_cnt > 0)
	{
		while (op_cnt > 0)
		{
			ra(a);
			op_cnt--;
		}
	}
	else
	{
		while (op_cnt < 0)
		{
			rra(a);
			op_cnt++;
		}
	}
}

void	ope_ab(t_stack *a, t_stack *b, int op_cnt)
{
	if (op_cnt > 0)
	{
		while (op_cnt > 0)
		{
			rr(a, b);
			op_cnt--;
		}
	}
	else
	{
		while (op_cnt < 0)
		{
			rrr(a, b);
			op_cnt++;
		}
	}
}

void	rotate_ab(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0 && cost_a < cost_b)
	{
		ope_ab(a, b, cost_a);
		exe_rotate_b(b, cost_b - cost_a);
	}
	else if (cost_a > 0 && cost_b > 0 && cost_a >= cost_b)
	{
		ope_ab(a, b, cost_b);
		exe_rotate_a(a, cost_a - cost_b);
	}
	else if (cost_a < 0 && cost_b < 0 && cost_a < cost_b)
	{
		ope_ab(a, b, cost_b);
		exe_rotate_a(a, cost_a - cost_b);
	}
	else if (cost_a < 0 && cost_b < 0 && cost_a >= cost_b)
	{
		ope_ab(a, b, cost_a);
		exe_rotate_b(b, cost_b - cost_a);
	}
	else
	{
		exe_rotate_a(a, cost_a);
		exe_rotate_b(b, cost_b);
	}
}
