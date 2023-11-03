/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/03 01:33:37 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_l(const char *str)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (LONG_MAX / 10 <= sign * nbr && LONG_MAX % 10 < (*str - '0'))
			return (sign * nbr);
		if (LONG_MIN / 10 >= sign * nbr && -1 * (LONG_MIN % 10) < (*str - '0'))
			return (LONG_MIN);
		nbr *= 10;
		nbr += (*str - '0');
		str++;
	}
	return (sign * nbr);
}

int	is_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
			i++;
		else if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_integer(char *str)
{
	if (ft_atoi_l(str) < INT_MIN || INT_MAX < ft_atoi_l(str))
		return (0);
	return (1);
}

int	has_duplication(int *values, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (values[i] == values[j])
			return (1);
		j++;
	}
	return (0);
}

int	*argvtoi(int argc, char *argv[])
{
	int	i;
	int	*values;

	values = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc - 1)
	{
		if (!is_numbers(argv[i + 1]) || !is_integer(argv[i + 1]))
		{
			ft_printf("Error\nNot Integer@@@\n");
			exit(0);
		}
		values[i] = ft_atoi(argv[i + 1]);
		if (has_duplication(values, i))
		{
			ft_printf("Error\nHas duplication\n");
			exit(0);
		}
		i++;
	}
	return (values);
}
