/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:41:36 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 20:26:34 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *stack)
{
	int	*v;

	v = get_values(stack);
	if (v[0] > v[1])
		swap(stack, 1);
	free(v);
}

void	sort3(t_stack *stack)
{
	int	*v;

	v = get_values(stack);
	if (v[0] < v[1] && v[1] < v[2])
	{
		free(v);
		return ;
	}
	else if (v[0] < v[1] && v[1] > v[2] && v[2] > v[0])
	{
		reverse_rotate(stack, 1);
		swap(stack, 1);
	}
	else if (v[0] > v[1] && v[1] < v[2] && v[2] > v[0])
		swap(stack, 1);
	else if (v[0] < v[1] && v[1] > v[2] && v[2] < v[0])
		reverse_rotate(stack, 1);
	else if (v[0] > v[1] && v[1] < v[2] && v[2] < v[0])
		rotate(stack, 1);
	else if (v[0] > v[1] && v[1] > v[2] && v[2] < v[0])
	{
		rotate(stack, 1);
		swap(stack, 1);
	}
	free(v);
}

void	sort4(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (is_asc_sorted(a))
		return ;
	node = NULL;
	while (a->size > 3)
	{
		if (node == NULL)
			node = a->top;
		if (node->ordinal == 0)
			pb(a, b);
		else
			rotate(a, 1);
		node = a->top;
	}
	sort3(a);
	rrb(b);
	pa(a, b);
}

void	sort5(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (is_asc_sorted(a))
		return ;
	node = NULL;
	while (a->size > 3)
	{
		if (node == NULL)
			node = a->top;
		if (node->ordinal == 0 || node->ordinal == 1)
			pb(a, b);
		else
			rotate(a, 1);
		node = a->top;
	}
	sort3(a);
	sort2(b);
	rrb(b);
	pa(a, b);
	rrb(b);
	pa(a, b);
}

void	sort(t_stack *a, t_stack *b, int argc)
{
	set_order(a);
	if (argc - 1 == 2)
		sort2(a);
	else if (argc - 1 == 3)
		sort3(a);
	else if (argc - 1 == 4)
		sort4(a, b);
	else if (argc - 1 == 5)
		sort5(a, b);
	else if (argc - 1 >= 6)
		turk_sort(a, b);
}
