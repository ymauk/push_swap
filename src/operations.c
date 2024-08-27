/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:37:27 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/27 17:34:01 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **a_list)
{
	int	temp;

	if (*a_list && (*a_list)->next)
	{
		temp = (*a_list)->data;
		(*a_list)->data = (*a_list)->next->data;
		(*a_list)->next->data = temp;
		ft_printf("sa\n");
	}
}

void	sb(t_node **b_list)
{
	int	temp;

	if (*b_list && (*b_list)->next)
	{
		temp = (*b_list)->data;
		(*b_list)->data = (*b_list)->next->data;
		(*b_list)->next->data = temp;
		ft_printf("sb\n");
	}
}

void	ss(t_node **a_list, t_node **b_list)
{
	int	temp_a;
	int	temp_b;

	if (*a_list && (*a_list)->next)
	{
		temp_a = (*a_list)->data;
		(*a_list)->data = (*a_list)->next->data;
		(*a_list)->next->data = temp_a;
	}
	if (*b_list && (*b_list)->next)
	{
		temp_b = (*b_list)->data;
		(*b_list)->data = (*b_list)->next->data;
		(*b_list)->next->data = temp_b;
	}
	ft_printf("ss\n");
}

void	pa(t_node **to_a, t_node **from_b)
{
	t_node	*temp;

	if (*from_b)
	{
		temp = *from_b;
		*from_b = (*from_b)->next;
		temp->next = *to_a;
		*to_a = temp;
		ft_printf("pa\n");
	}
}

void	pb(t_node **to_b, t_node **from_a)
{
	t_node	*temp;

	if (*from_a)
	{
		temp = *from_a;
		*from_a = (*from_a)->next;
		temp->next = *to_b;
		*to_b = temp;
		ft_printf("pb\n");
	}
}
