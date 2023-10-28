/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:35:27 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/28 20:52:04 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_swap(int argc, char *argv[])
{
	int		values_count;
	int		*values;
	t_stack	*a;
	// t_stack	*b;

	// 入力取得
	values_count = argc - 1;
	// printf("values_count:%d argv[1]:%s\n", values_count, argv[1]);
	values = argvtoi(argc, argv);
	// printf("values[%d]:%d\n", values_count - 1, values[values_count - 1]);

	// スタック初期化
	a = create_stack("stack_A", values, values_count);
    // b = create_stack("stack_B", values, values_count);
    print_stack(a);
    // print_stack(b);
    sa(a);
	print_stack(a);

    return 0;
}
