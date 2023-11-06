/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 13:37:07 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char **split_arg(char *argv[]){
	char **arg;
	arg = ft_split(argv[1], ' ');

	printf("arg[0] = %s\n", arg[0]);
	printf("arg[1] = %s\n", arg[1]);

	return arg;
}

int	main(int argc, char *argv[])
{
	int		*values;
	t_stack	*a;
	t_stack	*b;

	if(argc == 2){
		argv = split_arg(argv);
		argc	= 1;
		printf("argc = %d\n", argc);
		while(argv[argc-1])
			argc++;
		printf("argc = %d\n", argc);
		printf("argv[argc - 1] = %s\n", argv[argc - 1]);
	}

	printf("argc => %d\n", argc);
	printf("argv[0] => %s\n", argv[0]);

	if (is_invalid_arg(argc, argv))
		return (1);
	printf("###\n");
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
