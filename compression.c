/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:33:07 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/02 01:42:59 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compression(t_stack *stack)
{
	int	min;
	int	value;
	int	i;

	i = 0;
	while (i < stack->size)
	{
		value = stack->top->value;
		if (value < min)
			min = value;
		stack->top = stack->top->next;
		i++;
	}
}

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
}
