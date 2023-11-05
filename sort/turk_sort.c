/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:04:38 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 07:17:22 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// For a stack that is in descending order,
// obtain the node that should be top when pushing the value.
t_node	*find_next_in_desc(t_stack *b, int value)
{
	t_node	*node;

	if (max_of(b) < value || min_of(b) > value)
		return (max_node(b));
	node = NULL;
	while (1)
	{
		if (node == NULL)
			node = b->top;
		if (node->value < value && value < node->prev->value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

// For a stack that is in ascending order,
// obtain the node that should be top when pushing the value.
t_node	*find_next_in_asc(t_stack *a, int value)
{
	t_node	*node;

	if (max_of(a) < value || min_of(a) > value)
		return (min_node(a));
	node = NULL;
	while (1)
	{
		if (node == NULL)
			node = a->top;
		if (node->value > value && value > node->prev->value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	is_asc_sorted(t_stack *stack)
{
	t_node	*node;

	node = NULL;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (node != stack->bottom && node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

// push to b in descending order
void	pb_desc(t_stack *a, t_stack *b, t_node *node)
{
	t_node	*target;
	t_cost	*cost;
	t_cost	*min;

	cost = (t_cost *)malloc(sizeof(t_cost));
	min = (t_cost *)malloc(sizeof(t_cost));
	min->total = INT_MAX;
	while (node != a->top)
	{
		if (node == NULL)
			node = a->top;
		target = find_next_in_desc(b, node->value);
		cost->b = calc_cost(target->value, b);
		cost->a = calc_cost(node->value, a);
		cost->total = get_total_cost(cost->a, cost->b);
		if (min->total > cost->total)
		{
			min->total = cost->total;
			min->a = cost->a;
			min->b = cost->b;
		}
		node = node->next;
	}
	rotate_ab(a, b, min->a, min->b);
	pb(a, b);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		cost;

	if (is_asc_sorted(a))
		return ;
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
		pb_desc(a, b, NULL);
	sort3(a);
	while (b->size > 0)
	{
		node = find_next_in_asc(a, b->top->value);
		cost = calc_cost(node->value, a);
		exe_rotate_a(a, cost);
		pa(a, b);
	}
	node = find_next_in_asc(a, min_of(a) - 1);
	cost = calc_cost(node->value, a);
	exe_rotate_a(a, cost);
}
