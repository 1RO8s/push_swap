/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:36:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/25 04:07:17 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_summary(t_stack *stack)
{
	printf("--- %s ---\n", stack->name);
	if (stack->size > 0)
	{
		printf("top:%d ", stack->top->value);
		printf("bottom:%d ", stack->bottom->value);
	}
	printf("size:%d ", stack->size);
	printf("\n");
}

void	print_stack_values(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 1)
	{
		printf("no values\n");
		return ;
	}
	node = NULL;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

void	print_stack(t_stack *stack)
{
	print_stack_summary(stack);
	print_stack_values(stack);
}

void	print_node(t_node *node)
{
	printf("value:%d ", node->value);
	printf("ordinal:%d ", node->ordinal);
	printf("next:%d ", node->next->value);
	printf("prev:%d ", node->prev->value);
	printf("\n");
}
