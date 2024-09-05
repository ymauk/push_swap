/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_node2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:30:34 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/05 12:42:15 by ymauk            ###   ########.fr       */
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

// find last node of list
t_node	*ft_lstlast_ps(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

// find the min out of two values
int	min(int cheapest_a, int cheapest_b)
{
	if (cheapest_a < cheapest_b)
		return (cheapest_a);
	else
		return (cheapest_b);
}

// find the max out of two values
int	max(int cheapest_a, int cheapest_b)
{
	if (cheapest_a > cheapest_b)
		return (cheapest_a);
	else
		return (cheapest_b);
}
