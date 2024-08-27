/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:58:17 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/27 19:00:26 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_node **a_list, t_node **b_list)
{
	t_node	*second_last_a;
	t_node	*last_a;
	t_node	*second_last_b;
	t_node	*last_b;

	second_last_a = NULL;
	last_a = *a_list;
	while (last_a->next != NULL)
	{
		second_last_a = last_a;
		last_a = last_a->next;
	}
	second_last_a->next = NULL;
	ft_lstadd_front_ps(a_list, last_a);
	second_last_b = NULL;
	last_b = *b_list;
	while (last_b->next != NULL)
	{
		second_last_b = last_b;
		last_b = last_b->next;
	}
	second_last_b->next = NULL;
	ft_lstadd_front_ps(b_list, last_b);
	ft_printf("rrr\n");
}
