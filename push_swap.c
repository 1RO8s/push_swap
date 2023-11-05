/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/05 00:27:19 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*values;
	t_stack	*a;
	t_stack	*b;

	if (is_invalid_arg(argc, argv))
		return (1);
	values = argvtoi(argc, argv);
	if (has_duplication(values, argc - 1))
		return (1);
	a = create_stack('A', values, argc - 1);
	b = create_stack('B', NULL, 0);
	set_order(a);
	if (argc - 1 == 2)
		sort2(a);
	else if (argc - 1 == 3)
		sort3(a);
	else if (argc - 1 == 4)
		sort4(a, b);
	else if (argc - 1 == 5)
		sort5(a, b);
	else if (argc - 1 >= 6)
		turk_sort(a, b);
	free_stack(a);
	free_stack(b);
	free(values);
}
