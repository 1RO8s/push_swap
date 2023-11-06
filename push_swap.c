/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 14:11:31 by hnagasak         ###   ########.fr       */
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
	sort(a, b, argc);
	free_stack(a);
	free_stack(b);
	free(values);
}
