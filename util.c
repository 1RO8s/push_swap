/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:57:03 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/04 02:57:19 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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