/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:30:16 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/04 11:42:25 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_values(t_stack *stack, int *values, int values_count)
{
	int	i;

	if (values == NULL)
		return ;
	i = 0;
	while (i < values_count)
	{
		push(stack, values[values_count - i - 1]);
		i++;
	}
}

int	*get_values(t_stack *stack)
{
	int	*values;
	int	i;

	values = (int *)malloc(sizeof(int) * stack->size);
	i = 0;
	while (i < stack->size)
	{
		values[i] = stack->top->value;
		stack->top = stack->top->next;
		i++;
	}
	return (values);
}

/**
* Take the first element at the top of A and put it at the top of B.
* Do nothing if A is empty.
* @param[out] a stack of a
* @param[out] b stack of b
* @return void 
*/
t_stack	*create_stack(char id, int *values, int values_count)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->id = id;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	set_values(stack, values, values_count);
	return (stack);
}

int	pop(t_stack *stack)
{
	t_node	*remove;
	int		pop_value;

	if (stack->size < 1)
		return (-1);
	remove = stack->top;
	pop_value = remove->value;
	if (stack->size > 1)
	{
		stack->top = stack->top->next;
		stack->top->prev = stack->bottom;
		stack->bottom->next = stack->top;
	}
	else
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	free(remove);
	remove = NULL;
	stack->size--;
	return (pop_value);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = NULL;
	while (stack->size > 0)
	{
		if (node == NULL)
			node = stack->top;
		next = node->next;
		free(node);
		node = next;
		stack->size--;
	}
	free(stack);
}
