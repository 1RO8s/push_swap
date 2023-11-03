/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:41:36 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/03 23:53:29 by hnagasak         ###   ########.fr       */
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
		
	else if (v[0] < v[1] && v[1] > v[2] && v[2] > v[0]) // 1 3 2
	{
		reverse_rotate(stack, 1);
		swap(stack, 1);
	}
	else if (v[0] > v[1] && v[1] < v[2] && v[2] > v[0]) // 2 1 3
		swap(stack, 1);
	else if (v[0] < v[1] && v[1] > v[2] && v[2] < v[0]) // 2 3 1
		reverse_rotate(stack, 1);
	else if (v[0] > v[1] && v[1] < v[2] && v[2] < v[0]) // 3 1 2
		rotate(stack, 1);
	else if (v[0] > v[1] && v[1] > v[2] && v[2] < v[0]) // 3 2 1
	{
		rotate(stack, 1);
		swap(stack, 1);
	}
	free(v);
}

void	sort4(t_stack *a, t_stack *b)
{
	t_node	*node;

	// printf("--- sort4 ---\n");
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

	// printf("--- sort5 ---\n");
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
	// printf("--- pb done ---\n");
	// print_stack(a);
	// print_stack(b);
	sort3(a);
	sort2(b);
	// printf("--- sorted ---\n");
	rrb(b);
	pa(a, b);
	rrb(b);
	pa(a, b);
}

void	sort6(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = NULL;
	while (a->size > 3)
	{
		if (node == NULL)
			node = a->top;
		if (node->ordinal == 0 || node->ordinal == 1 || node->ordinal == 2)
			pb(a, b);
		else
			rotate(a, 1);
		node = a->top;
	}
	// print_stack(a);
	// print_stack(b);
	sort3(a);
	sort3(b);
	rrb(b);
	pa(a, b);
	rrb(b);
	pa(a, b);
	rrb(b);
	pa(a, b);
}
