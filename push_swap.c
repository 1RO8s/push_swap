/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/26 20:19:53 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argvtoi(int argc, char *argv[])
{
	int	i;
	int	*values;

	values = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc - 1)
	{
		values[i] = ft_atoi(argv[i + 1]);
		// printf("values[%d]:%d\n", i, values[i]);
		i++;
	}
	return (values);
}

int	main(int argc, char *argv[])
{
	int		values_count;
	int		*values;
	t_stack	*stca;
	t_stack	*stcb;

	// 入力取得
	values_count = argc - 1;
	// printf("values_count:%d argv[1]:%s\n", values_count, argv[1]);
	values = argvtoi(argc, argv);
	// printf("values[%d]:%d\n", values_count - 1, values[values_count - 1]);

	// スタック初期化
	stca = create_stack("stack_A", values, values_count);
	stcb = create_stack("stack_B", NULL, 0);
	print_stack(stca);
	// print_stack(stcb);
	if (values_count <= 3)
		sort3(stca);

	// ra(stca);
	// if (stack_size == 6)
	// 	sort6(values);
	// else
	// 	sort7(values);
	print_stack(stca);
	print_stack(stcb);
	// test();
}
