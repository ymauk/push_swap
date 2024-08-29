/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:23 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/29 16:41:26 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotation(t_node **a_list, t_node **b_list, t_vars *sets)
{
	int	closest_nbr;
	int	rotations_up[ft_lstsize_ps(a_list)];

	ft_min_max_b(b_list, sets);
	// printf("max_b: %d\n", sets->max_b);
	// printf("min_a: %d\n", sets->min_a);
	if ((*a_list)->data == sets->min_a)
		closest_nbr = sets->max_b;
	else
		closest_nbr = find_closest_number((*a_list)->data, b_list, sets);
	// printf("closest number: %d\n", closest_nbr);
	count_rotating_up_a(a_list,  )

}

int	count_rotating_up_a(t_node a_list, int a_value)
{
	
}

int	find_closest_number(int a_value, t_node **b_list, t_vars *sets)
{
	int		min_delta;
	int		closest_number;
	t_node	*temp_b;

	temp_b = *b_list;
	closest_number = -1;
	min_delta = INT_MAX;
	while (temp_b != NULL)
	{
		if (temp_b->data == sets->min_a)
			closest_number = sets->max_b;
		else if (temp_b->data < a_value)
		{
			if ((a_value - temp_b->data) < min_delta)
			{
				min_delta = (a_value - temp_b->data);
				closest_number = temp_b->data;
			}
		}
		temp_b = temp_b->next;
	}
	return (closest_number);
}
