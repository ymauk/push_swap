/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:37 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/04 18:05:18 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_rotation(t_node **a_list, t_node **b_list, t_vars *sets)
{
	execute_rotation2(a_list, b_list, sets);
	execute_rotation3(a_list, sets);
	execute_rotation4(b_list, sets);
	pb(b_list, a_list);
}

void	execute_rotation2(t_node **a_list, t_node **b_list, t_vars *sets)
{
	if (sets->cheapest_rtt_a < 0 && sets->cheapest_rtt_b < 0)
	{
		while (sets->cheapest_rtt_a < 0 && sets->cheapest_rtt_b < 0)
		{
			rrr(a_list, b_list);
			sets->cheapest_rtt_a++;
			sets->cheapest_rtt_b++;
		}
	}
	else if (sets->cheapest_rtt_a > 0 && sets->cheapest_rtt_b > 0)
	{
		while (sets->cheapest_rtt_a > 0 && sets->cheapest_rtt_b > 0)
		{
			rr(a_list, b_list);
			sets->cheapest_rtt_a--;
			sets->cheapest_rtt_b--;
		}
	}
}

void	execute_rotation3(t_node **a_list, t_vars *sets)
{
	if (sets->cheapest_rtt_a < 0)
	{
		while (sets->cheapest_rtt_a < 0)
		{
			rra(a_list);
			sets->cheapest_rtt_a++;
		}
	}
	else
	{
		while (sets->cheapest_rtt_a > 0)
		{
			ra(a_list);
			sets->cheapest_rtt_a--;
		}
	}
}

void	execute_rotation4(t_node **b_list, t_vars *sets)
{
	if (sets->cheapest_rtt_b < 0)
	{
		while (sets->cheapest_rtt_b < 0)
		{
			rrb(b_list);
			sets->cheapest_rtt_b++;
		}
	}
	else
	{
		while (sets->cheapest_rtt_b > 0)
		{
			rb(b_list);
			sets->cheapest_rtt_b--;
		}
	}
}

void	push_to_a(t_node **a_list, t_node **b_list, t_vars *sets)
{
	printf("sets cheapest rtt a: %d\n", sets->cheapest_rtt_a);
	if (sets->cheapest_rtt_a < 0)
	{
		while (sets->cheapest_rtt_a < 0)
		{
			rra(a_list);
			sets->cheapest_rtt_a++;
		}
	}
	if (sets->cheapest_rtt_a > 0)
	{
		while (sets->cheapest_rtt_a > 0)
		{
			ra(a_list);
			sets->cheapest_rtt_a--;
		}
	}
	pa(a_list, b_list);
}
