/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:23 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/05 12:52:52 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_cheapest_rotation(t_node *a_list, t_node *b_list, t_vars *sets)
{
	t_node	*temp_a;
	int		closest_nbr;
	int		spot_in_a;
	int		nbr_rotations;

	temp_a = a_list;
	spot_in_a = 0;
	sets->cheapest_rtt = INT_MAX;
	while (temp_a != NULL)
	{
		ft_min_max_b(b_list, sets);
		if (temp_a->data == sets->min_a)
			closest_nbr = sets->max_b;
		else
			closest_nbr = find_closest_number(temp_a->data, b_list);
		if (spot_in_a <= (ft_lstsize_ps(a_list) / 2))
			nbr_rotations = spot_in_a;
		else
			nbr_rotations = (ft_lstsize_ps(a_list) - spot_in_a) * -1;
		spot_in_a++;
		cmp_rtt(nbr_rotations, cheapest_rtt_b(b_list, closest_nbr), sets);
		temp_a = temp_a->next;
	}
}

void	find_cheapest_rotation2(t_node *a_list, t_node *b_list, t_vars *sets)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		closest_nbr;
	int		nbr_rotation;

	temp_a = a_list;
	temp_b = b_list;
	sets->cheapest_rtt_a = INT_MAX;
	while (temp_a != NULL)
	{
		ft_min_max_a(a_list, sets);
		if (temp_b->data > sets->max_a)
			closest_nbr = sets->min_a;
		else
			closest_nbr = find_closest_number2(temp_b->data, a_list);
		nbr_rotation = cheapest_rtt_b(a_list, closest_nbr);
		if (abs(nbr_rotation) < sets->cheapest_rtt_a)
			sets->cheapest_rtt_a = nbr_rotation;
		temp_a = temp_a->next;
	}
}

int	cheapest_rtt_b(t_node *list, int c_nbr)
{
	t_node	*temp;
	int		spot_in;

	temp = list;
	spot_in = 0;
	while (temp != NULL)
	{
		if ((temp->data == c_nbr) && (spot_in <= ft_lstsize_ps(list) / 2))
			return (spot_in);
		else if (temp->data == c_nbr)
			return ((ft_lstsize_ps(list) - spot_in) * -1);
		spot_in++;
		temp = temp->next;
	}
	return (0);
}

int	find_closest_number(int a_value, t_node *b_list)
{
	int		min_delta;
	int		closest_number;
	t_node	*temp_b;

	temp_b = b_list;
	min_delta = INT_MAX;
	while (temp_b != NULL)
	{
		if (temp_b->data < a_value)
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

int	find_closest_number2(int b_value, t_node *a_list)
{
	int		min_delta;
	int		closest_number;
	t_node	*temp_a;

	temp_a = a_list;
	min_delta = INT_MAX;
	while (temp_a != NULL)
	{
		if (temp_a->data > b_value)
		{
			if ((temp_a->data - b_value) < min_delta)
			{
				min_delta = (temp_a->data - b_value);
				closest_number = temp_a->data;
			}
		}
		temp_a = temp_a->next;
	}
	return (closest_number);
}
