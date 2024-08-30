/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:23 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/30 14:18:57 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find(t_vars *sets)
{
	int	min;

	min = sets->min_a;
	printf("arrived");
}

void	find_cheapest_rotation(t_node *a_list, t_node *b_list, t_vars *sets)
{
	printf("end\n");
	t_node	*temp_a;
	int		closest_nbr;
	int		spot_in_a;
	int		nbr_rotations;

	temp_a = a_list;
	spot_in_a = 0;
	while (temp_a != NULL)
	{
		ft_min_max_b(b_list, sets);
		if (temp_a->data == sets->min_a)
			closest_nbr = sets->max_b;
		else
			closest_nbr = find_closest_number(temp_a->data, b_list, sets);
		if (spot_in_a <= (ft_lstsize_ps(a_list) / 2))
			nbr_rotations = spot_in_a;
		else
			nbr_rotations = (ft_lstsize_ps(a_list) - spot_in_a);
			// nbr_rotations = (spot_in_a - (ft_lstsize_ps(a_list) / 2));
		printf("spot and nbr of rotations up: %d in a_list: %d closest number: %d nbr of rotations: %d\n", spot_in_a, temp_a->data, closest_nbr, nbr_rotations);
		spot_in_a++;
		temp_a = temp_a->next;
	}
}

int	find_closest_number(int a_value, t_node *b_list, t_vars *sets)
{
	int		min_delta;
	int		closest_number;
	t_node	*temp_b;

	temp_b = b_list;
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

// int	count_rotating_up_a(t_node a_list, int a_value)
// {
	
// }