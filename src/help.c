/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:19:09 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/04 13:00:46 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	counting_size(int argc, char **argv)
{
	int		counter;
	int		i;
	char	**split;

	argc = 0;
	counter = 0;
	i = 0;
	split = ft_split(argv[1], ' ');
	while (split[i] != NULL)
	{
		i++;
		counter++;
	}
	free (split);
	return (counter);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

// find the min out of two values
int	min(int cheapest_a, int cheapest_b)
{
	if (cheapest_a < cheapest_b)
		return (cheapest_a);
	else
		return (cheapest_b);
}

// find the max out of two values
int	max(int cheapest_a, int cheapest_b)
{
	if (cheapest_a > cheapest_b)
		return (cheapest_a);
	else
		return (cheapest_b);
}

// calculate the absolut
int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}
