/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:21:41 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/06 13:00:06 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cmp_rtt(int chp_a, int chp_b, t_vars *sets)
{
	int	cmb_rtt;

	cmb_rtt = INT_MAX;
	if (chp_a >= 0 && chp_b >= 0)
		cmb_rtt = max(chp_a, chp_b);
	else if (chp_a < 0 && chp_b < 0)
		cmb_rtt = max(abs(chp_a), abs(chp_b));
	else
		cmb_rtt = abs(chp_a) + abs(chp_b);
	if (cmb_rtt < sets->cheapest_rtt)
	{
		sets->cheapest_rtt = cmb_rtt;
		sets->cheapest_rtt_a = chp_a;
		sets->cheapest_rtt_b = chp_b;
	}
}

void	sort_a(t_node **a_list, t_vars *sets)
{
	t_node	*temp_a;
	int		spot_in_a;
	int		nbr_rotations;

	temp_a = *a_list;
	spot_in_a = 0;
	ft_min_max_a(temp_a, sets);
	while (temp_a != NULL)
	{
		if (temp_a->data == sets->min_a)
			break ;
		spot_in_a++;
		temp_a = temp_a->next;
	}
	if (spot_in_a <= sets->size_a / 2)
		nbr_rotations = spot_in_a;
	else
		nbr_rotations = ((sets->size_a - spot_in_a) * -1);
	sets->cheapest_rtt_a = nbr_rotations;
	execute_rotation3(a_list, sets);
}
