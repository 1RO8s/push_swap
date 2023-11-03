/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:04:38 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/04 02:13:21 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_b(t_stack *b, int op_cnt)
{
	if (op_cnt > 0)
	{
		while (op_cnt > 0)
		{
			rb(b);
			op_cnt--;
		}
	}
	else
	{
		while (op_cnt < 0)
		{
			rrb(b);
			op_cnt++;
		}
	}
}

void	operation_a(t_stack *a, int op_cnt)
{
	if (op_cnt > 0)
	{
		while (op_cnt > 0)
		{
			ra(a);
			op_cnt--;
		}
	}
	else
	{
		while (op_cnt < 0)
		{
			rra(a);
			op_cnt++;
		}
	}
}

void	ope_ab(t_stack *a, t_stack *b, int op_cnt)
{
	if (op_cnt > 0)
	{
		while (op_cnt > 0)
		{
			rr(a, b);
			op_cnt--;
		}
	}
	else
	{
		while (op_cnt < 0)
		{
			rrr(a, b);
			op_cnt++;
		}
	}
}

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

/**
* Take the first element at the top of B and put it at the top of A.
* Do nothing if B is empty.
* @param[out] value 
* @param[out] b stack of b
* @return number of operations to push a to B.rotate" is a positive value,
	"reverse_rotate" is a negative value
*/
int	calc_cost(int value, t_stack *stack)
{
	int		i;
	t_node	*node;
	int		mid;

	mid = stack->size / 2;
	node = NULL;
	i = 0;
	while (node != stack->top)
	{
		if (node == NULL)
			node = stack->top;
		if (node->value == value)
			break ;
		node = node->next;
		i++;
	}
	if (i < mid)
		return (i);
	else
		return (i - stack->size);
}

// valueをpushするとき、topになるべきノードを取得
t_node	*get_target_node(t_stack *b, int value)
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

t_node	*get_target_node_a(t_stack *a, int value)
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

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_total_cost(int cost_a, int cost_b)
{
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) < ft_abs(cost_b))
			return (ft_abs(cost_b));
		else
			return (ft_abs(cost_a));
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
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

void	exec_push(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a < cost_b)
		{
			ope_ab(a, b, cost_a);
			operation_b(b, cost_b - cost_a);
		}
		else
		{
			ope_ab(a, b, cost_b);
			operation_a(a, cost_a - cost_b);
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
		{
			ope_ab(a, b, cost_b);
			operation_a(a, cost_a - cost_b);
		}
		else
		{
			ope_ab(a, b, cost_a);
			operation_b(b, cost_b - cost_a);
		}
	}
	else
	{
		operation_a(a, cost_a);
		operation_b(b, cost_b);
	}
	pb(a, b);
}

typedef struct s_cost
{
	int		a;
	int		b;
	int		total;
}			t_cost;

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
		target = get_target_node(b, node->value);
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
	exec_push(a, b, min->a, min->b);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*tgt;
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
		tgt = get_target_node_a(a, b->top->value);
		cost = calc_cost(tgt->value, a);
		operation_a(a, cost);
		pa(a, b);
	}
	tgt = get_target_node_a(a, min_of(a) - 1);
	cost = calc_cost(tgt->value, a);
	operation_a(a, cost);
}
