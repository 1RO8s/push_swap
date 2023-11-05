/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:33:07 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/05 00:26:45 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[j] < values[i])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	set_order(t_stack *stack)
{
	t_node	*tmp;
	int		*values;
	int		i;

	values = get_values(stack);
	bubble_sort(values, stack->size);
	tmp = NULL;
	while (tmp != stack->top)
	{
		if (tmp == NULL)
			tmp = stack->top;
		i = 0;
		while (i < stack->size)
		{
			if (tmp->value == values[i])
			{
				tmp->ordinal = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(values);
}
