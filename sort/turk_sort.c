/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:04:38 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/02 01:10:38 by hnagasak         ###   ########.fr       */
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
		return (ft_abs(cost_a) < ft_abs(cost_b) ? ft_abs(cost_b) : ft_abs(cost_a));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

int is_asc_sorted(t_stack *stack){
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

void	turk_sort(t_stack *a, t_stack *b)
{
	int		cost_b;
	int		cost_a;
	t_node	*node;
	t_node	*node_b;
	int		total_cost;
	int		min_cost;
	int		min_cost_a;
	int		min_cost_b;
	t_node	*tgt;
	int		cost;
	// t_node	*min_node;

	// printf("--- turk_sort ---\n");
	if (is_asc_sorted(a))
		return;
	pb(a, b);
	pb(a, b);
	// print_stack(a);
	// print_stack(b);
	while (a->size > 3)
	{
		// printf("_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n");
		// printf("%d < %d || %d > %d:", max_of(b), a->top->value, min_of(b),
		// 		a->top->value);
		// printf("%s\n", (max_of(b) < a->top->value
		// || min_of(b) > a->top->value) ? "True" : "False");
		// if (max_of(b) < a->top->value || min_of(b) > a->top->value)
		node = NULL;
		min_cost = INT_MAX;
		while (node != a->top) // すべてのaに対して操作数を計算
		{
			if (node == NULL)
				node = a->top;
			// aをpushする先のbと、それをtopに移動するまでの操作回数を計算
			node_b = get_target_node(b, node->value); // bの一番上になるノードを取得
			cost_b = calc_cost(node_b->value, b);     // 一番上に移動するまでのコストを計算
			// nodeをtopに移動するまでのコストを計算
			cost_a = calc_cost(node->value, a);
			// printf("a = %2d[%d] ,", node->value, cost_a);
			// printf("b = %2d[%d] ,", node_b->value, cost_b);
			total_cost = get_total_cost(cost_a, cost_b);
			// printf("total:%2d\n", total_cost);
			if (min_cost > total_cost)
			{
				min_cost = total_cost;
				// min_node = node;
				min_cost_a = cost_a;
				min_cost_b = cost_b;
			}
			node = node->next;
		}
		// min_costに従って、rotate or reverse_rotate
		// printf("min_node:%d a[%d] b[%d]\n", min_node->value, min_cost_a,min_cost_b);
		if (min_cost_a > 0 && min_cost_b > 0)
		{
			if (min_cost_a < min_cost_b)
			{
				ope_ab(a, b, min_cost_a);
				operation_b(b, min_cost_b - min_cost_a);
			}
			else
			{
				ope_ab(a, b, min_cost_b);
				operation_a(a, min_cost_a - min_cost_b);
			}
		}
		else if (min_cost_a < 0 && min_cost_b < 0)
		{
			if (min_cost_a < min_cost_b)
			{
				ope_ab(a, b, min_cost_b);
				operation_a(a, min_cost_a - min_cost_b);
			}
			else
			{
				ope_ab(a, b, min_cost_a);
				operation_b(b, min_cost_b - min_cost_a);
			}
		}
		else
		{
			operation_a(a, min_cost_a);
			operation_b(b, min_cost_b);
		}
		pb(a, b);
		// print_stack(a);
		// print_stack(b);
	}
	// printf("-----------------------\n");
	// printf("      pb complete      \n");
	// printf("-----------------------\n");
	sort3(a);
	// printf("-----------------------\n");
	// printf("      sort a      \n");
	// printf("-----------------------\n");
	// print_stack(a);
	// print_stack(b);
	// bからaに戻す
	while (b->size > 0)
	{
		// printf("_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n");
		tgt = get_target_node_a(a, b->top->value);
		cost = calc_cost(tgt->value, a);
		// printf("b:%d tgt:%d cost:%d\n", b->top->value, tgt->value, cost);
		operation_a(a, cost);
		pa(a, b);
		// print_stack(a);
		// print_stack(b);
	}
	// printf("-----------------------\n");
	// printf("      pa complete      \n");
	// printf("-----------------------\n");
	tgt = get_target_node_a(a, min_of(a) - 1);
	cost = calc_cost(tgt->value, a);
	operation_a(a, cost);
	// print_stack(a);
	// print_stack(b);
}
