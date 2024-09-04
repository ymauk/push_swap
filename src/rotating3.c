/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:21:41 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/04 18:03:33 by ymauk            ###   ########.fr       */
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
