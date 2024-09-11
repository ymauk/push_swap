/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:49:17 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/11 16:12:49 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_string(char **string)
{
	no_ints(string);
	duplicates(string);
	size_int(string);
	single_nbr(string);
}

void	single_nbr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	if (i == 1)
	{
		ft_free_all(str);
		exit (0);
	}
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
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_handling(str);
		i++;
	}
}
