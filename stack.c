/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:30:16 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/25 04:34:07 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char *_name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->name = _name;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
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
