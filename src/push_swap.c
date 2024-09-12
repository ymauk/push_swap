/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:45 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/11 16:38:27 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a_list;
	t_node	*b_list;

	a_list = NULL;
	b_list = NULL;
	if (argc != 1)
	{
		a_list = parsing1(a_list, argc, argv);
		start_sorting(&a_list, &b_list, ft_lstsize_ps(a_list));
		free_all_list(a_list);
	}
	return (0);
}
