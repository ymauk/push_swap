/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:37:27 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/06 18:22:15 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// swap first two elements in stack a
void	sa(t_node **a_list)
{
	int	temp;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	temp = (*a_list)->data;
	(*a_list)->data = (*a_list)->next->data;
	(*a_list)->next->data = temp;
	ft_printf("sa\n");
}

// swap first two elements in stack b
void	sb(t_node **b_list)
{
	int	temp;

	if (*b_list == NULL || (*b_list)->next == NULL)
		return ;
	temp = (*b_list)->data;
	(*b_list)->data = (*b_list)->next->data;
	(*b_list)->next->data = temp;
	ft_printf("sb\n");
}

// swap first two elements in stack a and stack b
void	ss(t_node **a_list, t_node **b_list)
{
	int	temp_a;
	int	temp_b;

	if (*a_list != NULL && (*a_list)->next != NULL)
	{
		temp_a = (*a_list)->data;
		(*a_list)->data = (*a_list)->next->data;
		(*a_list)->next->data = temp_a;
	}
	if (*b_list != NULL && (*b_list)->next != NULL)
	{
		temp_b = (*b_list)->data;
		(*b_list)->data = (*b_list)->next->data;
		(*b_list)->next->data = temp_b;
	}
	ft_printf("ss\n");
}

//push first element from b to top of a
void	pa(t_node **to_a, t_node **from_b)
{
	t_node	*temp;

	if (*from_b == NULL)
		return ;
	temp = *from_b;
	*from_b = (*from_b)->next;
	temp->next = *to_a;
	*to_a = temp;
	ft_printf("pa\n");
}

//push first element from a to top of b
void	pb(t_node **to_b, t_node **from_a)
{
	t_node	*temp;

	if (*from_a == NULL)
		return ;
	temp = *from_a;
	*from_a = (*from_a)->next;
	temp->next = *to_b;
	*to_b = temp;
	ft_printf("pb\n");
}
