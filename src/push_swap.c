/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:45 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/23 10:40:18 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a_list;
	t_node	*b_list;

	a_list = NULL;
	b_list = NULL;
	if (argc <= 1)
		return (ft_printf("%sWrong amount of arguments!\n%s", R, DC));
	parsing1(a_list, argc, argv);
	return (0);
}
