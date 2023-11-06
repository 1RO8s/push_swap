/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/11/06 21:28:41 by hnagasak         ###   ########.fr       */
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

int	is_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			i++;
		else if (
			(str[i] == '-' || str[i] == '+') &&
			('0' <= str[i+1] && str[i+1] <= '9'))
			i++;
		else if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (ft_atoi_l(str) < INT_MIN || INT_MAX < ft_atoi_l(str))
		return (0);
	return (1);
}

int	is_invalid_arg(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
	{
		// ft_printf("Error\nmissing arguments\n");
		return (1);
	}
	i = 0;
	while (i < argc - 1)
	{
		if (!is_integer(argv[i + 1]))
		{
			ft_printf("Error\nNot Integer\n");
			return (1);
		}
		i++;
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
		values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (values);
}

int	has_duplication(int *values, int values_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < values_size)
	{
		j = 0;
		while (j < i)
		{
			if (values[i] == values[j])
			{
				ft_printf("Error\nDuplicate number\n");
				free(values);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
