/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:46:59 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 14:21:27 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_of(t_stack *stack)
{
	int		max;
	t_node	*node;

	max = stack->top->value;
	node = NULL;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	min_of(t_stack *stack)
{
	int		min;
	t_node	*node;

	min = stack->top->value;
	node = NULL;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}

t_node	*max_node(t_stack *stack)
{
	t_node	*max_node;
	t_node	*node;

	max_node = stack->top;
	node = NULL;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (max_node->value < node->value)
			max_node = node;
		node = node->next;
	}
	return (max_node);
}

t_node	*min_node(t_stack *stack)
{
	t_node	*min_node;
	t_node	*node;

	min_node = stack->top;
	node = NULL;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (min_node->value > node->value)
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
