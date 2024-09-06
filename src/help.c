/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:19:09 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/06 11:42:31 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	counting_size(char **argv, int argc)
{
	int		counter;
	int		i;
	int		j;
	char	**split;

	counter = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split != NULL)
		{
			j = 0;
			while (split[j] != NULL)
			{
				counter++;
				j++;
			}
			ft_free_all(split);
		}
		i++;
	}
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

// calculate the absolut
int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void	free_all_list(t_node *a_list)
{
	t_node	*temp;

	while (a_list != NULL)
	{
		temp = a_list->next;
		free(a_list);
		a_list = temp;
	}
}
//free funktion die alles bisher erbrachte freed
//inklusive exit welche die Funktion beendet