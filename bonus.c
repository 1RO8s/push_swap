/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 21:49:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_ope(t_stack *a, t_stack *b, char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		swap(a, 0);
	else if (ft_strncmp(str, "sb", 2) == 0)
		swap(b, 0);
	else if (ft_strncmp(str, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(str, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(str, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "ra", 2) == 0)
		rotate(a, 0);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate(b, 0);
	else if (ft_strncmp(str, "rr", 2) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rra", 3) == 0)
		reverse_rotate(a, 0);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		reverse_rotate(b, 0);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		rrr(a, b);
	else
		ft_printf("Error\n");
}

// return 0, if read fails
int	input_opes(t_stack *a, t_stack *b, char *input)
{
	size_t	bytes;
	char	**opes;
	int		i;

	printf("--- input_ope ---\n");

	while (1)
	{
		ft_printf("+");
		bytes = read(STDIN_FILENO, input, sizeof(input));
		if (bytes < 0)
			return (0);
		input[bytes] = '\0';
		opes = ft_split(input, '\n');
		i = 0;
		while (opes[i] != NULL)
		{
			exe_ope(a, b, opes[i]);
			i++;
		}
		free(opes);
		opes = NULL;
		if (is_asc_sorted(a))
			break ;
	}
	printf("--- looped ---\n");
	return (1);
}

void	free_memories(t_stack *a, t_stack *b, int *values)
{
	free_stack(a);
	a = NULL;
	free_stack(b);
	b = NULL;
	free(values);
	values = NULL;
}

int	main(int argc, char *argv[])
{
	int		values_count;
	int		*values;
	char	input[100];
	t_stack	*a;
	t_stack	*b;

	printf("--- main ---\n");
	values_count = argc - 1;
	values = argvtoi(argc, argv);
	a = create_stack('A', values, values_count);
	b = create_stack('B', NULL, 0);
	printf("--- created stack ---\n");
	if (!input_opes(a, b, input))
	{
		printf("fail\n");
		free_memories(a, b, values);
		return (1);
	}
	printf("--- exec ---\n");
	if (is_asc_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	free(values);
}
