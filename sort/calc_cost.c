/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:16:47 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 07:17:16 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* Take the first element at the top of B and put it at the top of A.
* Do nothing if B is empty.
* @param[out] value 
* @param[out] b stack of b
* @return number of operations to push a to B.rotate" is a positive value,
	"reverse_rotate" is a negative value
*/
int	calc_cost(int value, t_stack *stack)
{
	int		i;
	t_node	*node;
	int		mid;

	mid = stack->size / 2;
	node = NULL;
	i = 0;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (node->value == value)
			break ;
		node = node->next;
		i++;
	}
	if (i < mid)
		return (i);
	else
		return (i - stack->size);
}

int	get_total_cost(int cost_a, int cost_b)
{
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) < ft_abs(cost_b))
			return (ft_abs(cost_b));
		else
			return (ft_abs(cost_a));
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}
