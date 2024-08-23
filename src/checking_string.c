/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:49:17 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/23 14:22:55 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_string(char **string)
{
	no_ints(string);
	duplicates(string);
	size_int(string);
}

void	no_ints(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if (str[i][j] == '-')
		{
			j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				error_handling(str);
		}
		while (str[i][j] != '\0')
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				error_handling(str);
			j++;
		}
		i++;
	}
}

void	duplicates(char **str)
{
	int	i;
	int	nbr1;
	int	nbr2;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		nbr1 = ft_atoi(str[i]);
		j = i + 1;
		while (str[j] != NULL)
		{
			nbr2 = ft_atoi(str[j]);
			if (nbr1 == nbr2)
				error_handling(str);
			j++;
		}
		i++;
	}
}

void	size_int(char **str)
{
	int		i;
	long	nbr;

	i = 0;
	while (str[i] != NULL)
	{
		nbr = ft_atol(str[i]);
		printf("%ld\n", nbr);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_handling(str);
		i++;
	}
}
