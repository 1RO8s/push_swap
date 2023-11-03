/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/04 00:51:28 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char *argv[])
{
	int		values_size;
	int		*values;
	t_stack	*stca;
	t_stack	*stcb;

	// 入力取得
	values_size = argc - 1;
	// printf("values_size:%d argv[1]:%s\n", values_size, argv[1]);
	if (argc == 1)
	{
		ft_printf("Error\nartuments is empty\n");
		return (0);
	}
	values = argvtoi(argc, argv);
	// printf("values[%d]:%d\n", values_size - 1, values[values_size - 1]);
	// printf("atoi:%d\n", ft_atoi("a"));
	// スタック初期化
	// printf("values[0]:%d\n",values[0]);
	// printf("values_size:%d\n",values_size);
	stca = create_stack('A', values, values_size);
	stcb = create_stack('B', NULL, 0);
	// printf("values[0]:%d\n",values[0]);
	// stcb = create_stack("stack_B",values, values_size);
	set_order(stca);
	// printf("### 座標圧縮\n");
	if (values_size == 2)
		sort2(stca);
	else if (values_size == 3)
		sort3(stca);
	else if (values_size == 4)
		sort4(stca, stcb);
	else if (values_size == 5)
		sort5(stca, stcb);
	else if (values_size == 6)
		sort6(stca, stcb);
	else if (values_size >= 7)
		turk_sort(stca, stcb);
	// // // else
	// // 	sort7(values);
	// printf("### ソート終了\n");
	free_stack(stca);
	free_stack(stcb);
	free(values);
	// test_swap(argc,argv);
}
