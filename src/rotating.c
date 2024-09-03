/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:23 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/03 19:04:12 by ymauk            ###   ########.fr       */
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
		printf("nbr a: %d closest nbr: %d\n", temp_a->data, closest_nbr);
		if (spot_in_a <= (ft_lstsize_ps(a_list) / 2))
			nbr_rotations = spot_in_a;
		else
			nbr_rotations = (ft_lstsize_ps(a_list) - spot_in_a) * -1;
		spot_in_a++;
		cmp_rtt(nbr_rotations, cheapest_rtt_b(b_list, closest_nbr), sets);
		temp_a = temp_a->next;
	}
}

void	execute_rotation(t_node **a_list, t_node **b_list, t_vars *sets)
{
	int	rtt_a;
	int	rtt_b;

	rtt_a = sets->cheapest_rtt_a;
	rtt_b = sets->cheapest_rtt_b;
	printf("b list: %d\n", (*b_list)->data);
	printf("rtt a: %d, rtt b: %d\n", rtt_a, rtt_b);
	if (rtt_a < 0)
	{
		while (rtt_a < 0)
		{
			rra(a_list);
			rtt_a++;
		}
	}
	else
	{
		while (rtt_a > 0)
		{
			ra(a_list);
			rtt_a--;
		}
	}
	if (rtt_b < 0)
	{
		while (rtt_b < 0)
		{
			rrb(b_list);
			rtt_b++;
		}
	}
	else
	{
		while (rtt_b > 0)
		{
			rb(b_list);
			rtt_b--;
		}
	}
	// t_node *temp = *a_list;
	// t_node *temp_b = *b_list;
	// printf("Liste a_list nach operation:\n");
	// while (temp != NULL)
	// {
	// 	printf("%d\n", temp->data);
	// 	temp = temp->next;
	// }
	// printf("Liste b_list nach operation:\n");
	// while (temp_b != NULL)
	// {
	// 	printf("%d\n", temp_b->data);
	// 	temp_b = temp_b->next;
	// }
	pb(b_list, a_list);
}

void	cmp_rtt(int cheapest_a, int cheapest_b, t_vars *sets)
{
	int	combined_rotations;
	int	temp_ch_a;
	int	temp_ch_b;

	temp_ch_a = cheapest_a;
	temp_ch_b = cheapest_b;
	if (cheapest_a < 0)
		temp_ch_a *= -1;
	if (cheapest_b < 0)
		temp_ch_b *= -1;
	combined_rotations = temp_ch_a + temp_ch_b;
	if (combined_rotations < sets->cheapest_rtt)
	{
		sets->cheapest_rtt = combined_rotations;
		sets->cheapest_rtt_a = cheapest_a;
		sets->cheapest_rtt_b = cheapest_b;
	}
}

int	cheapest_rtt_b(t_node *b_list, int c_nbr)
{
	t_node	*temp_b;
	int		spot_in_b;

	temp_b = b_list;
	spot_in_b = 0;
	while (temp_b != NULL)
	{
		// printf("number in b: %d c_nbr: %d\n", temp_b->data, c_nbr);
		// printf("spot from c_nbr in stack b: %d\n", spot_in_b);
		if ((temp_b->data == c_nbr) && (spot_in_b <= ft_lstsize_ps(b_list) / 2))
			return (spot_in_b);
		else if (temp_b->data == c_nbr)
			return ((ft_lstsize_ps(b_list) - spot_in_b) * -1);
		spot_in_b++;
		temp_b = temp_b->next;
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
