/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_node2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:30:34 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/30 12:57:59 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// finding the min and max elenent of the list b
void	ft_min_max_b(t_node *lst, t_vars *sets)
{
	t_node	*temp;

	temp = lst;
	sets->max_b = temp->data;
	sets->min_b = temp->data;
	while (temp != NULL)
	{
		if (temp->data > sets->max_b)
			sets->max_b = temp->data;
		else if (temp->data < sets->min_b)
			sets->min_b = temp->data;
		temp = temp->next;
	}
}

// starting size of list a
void	beginsize_a(t_node *lst, t_vars *sets)
{
	sets->size_a = 0;
	while (lst != 0)
	{
		sets->size_a++;
		lst = lst->next;
	}
}
