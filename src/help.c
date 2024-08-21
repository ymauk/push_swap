/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:19:09 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/21 14:51:51 by ymauk            ###   ########.fr       */
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
