/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:41:36 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/28 20:27:46 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *a)
{
	int	*v;

	v = get_values(a);
	if (v[0] > v[1])
		sa(a);
}

void	sort3(t_stack *a)
{
	int	*v;

	v = get_values(a);
	if (v[0] < v[1] && v[1] < v[2]) // 1 2 3
		return ;
	else if (v[0] < v[1] && v[1] > v[2] && v[2] > v[0]) // 1 3 2
	{
		rra(a);
		sa(a);
	}
	else if (v[0] > v[1] && v[1] < v[2] && v[2] > v[0]) // 2 1 3
		sa(a);
	else if (v[0] < v[1] && v[1] > v[2] && v[2] < v[0]) // 2 3 1
		rra(a);
	else if (v[0] > v[1] && v[1] < v[2] && v[2] < v[0]) // 3 1 2
		ra(a);
	else if (v[0] > v[1] && v[1] > v[2] && v[2] < v[0]) // 3 2 1
	{
		ra(a);
		sa(a);
	}
}

void	sort3b(t_stack *b)
{
	int	*v;

	ft_printf("<sort3b >\n");
	v = get_values(b);
	if (v[0] < v[1] && v[1] < v[2]) // 1 2 3
		return ;
	else if (v[0] < v[1] && v[1] > v[2] && v[2] > v[0]) // 1 3 2
	{
		rrb(b);
		sb(b);
	}
	else if (v[0] > v[1] && v[1] < v[2] && v[2] > v[0]) // 2 1 3
		sb(b);
	else if (v[0] < v[1] && v[1] > v[2] && v[2] < v[0]) // 2 3 1
		rrb(b);
	else if (v[0] > v[1] && v[1] < v[2] && v[2] < v[0]) // 3 1 2
		rb(b);
	else if (v[0] > v[1] && v[1] > v[2] && v[2] < v[0]) // 3 2 1
	{
		rb(b);
		sb(b);
	}
	ft_printf("< sort3b/>\n");
}

void	sort6(t_stack *a, t_stack *b)
{
	t_node *node;

	printf("--- sort6 ---\n");
	
	// add 3 numbers to stack b
	node = NULL;
	while(a->size > 3)
	{
		if(node == NULL)
			node = a->top;
		if(node->ordinal == 0 || node->ordinal == 1 || node->ordinal == 2)
		{
			pb(a, b);
			// node = a->top;
		}
		else
			ra(a);
		node = a->top;
	}
	// sort3(a);
	sort3b(b);

	printf("--- sorted ---\n");

	print_stack(b);
	rrb(b);
	// pa(a, b);
	// rrb(b);
	// pa(a, b);
	// rrb(b);
	// pa(a, b);
	print_stack(b);
}
