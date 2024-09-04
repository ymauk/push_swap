/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:02:18 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/04 09:30:34 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a_list)
{
	t_node	*temp;

	temp = *a_list;
	*a_list = (*a_list)->next;
	temp->next = NULL;
	ft_lstadd_back_ps(a_list, temp);
	ft_printf("ra\n");
}

void	rb(t_node **b_list)
{
	t_node	*temp;

	temp = *b_list;
	*b_list = (*b_list)->next;
	temp->next = NULL;
	ft_lstadd_back_ps(b_list, temp);
	ft_printf("rb\n");
	// t_node  *first;
    // t_node  *second;
    // t_node  *last;
    // if (*b_list)
    // {
    //     first = *b_list;
    //     if (first->next)
    //     {
    //         second = first->next;
    //         last = ft_lstlast_ps(first);
    //         last->next = first;
    //         first->next = NULL;
    //         *b_list = second;
    //     }
    // }
    // ft_printf("rb\n");
}

void	rr(t_node **a_list, t_node **b_list)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = *a_list;
	*a_list = (*a_list)->next;
	temp_a->next = NULL;
	ft_lstadd_back_ps(a_list, temp_a);
	temp_b = *b_list;
	*b_list = (*b_list)->next;
	temp_b->next = NULL;
	ft_lstadd_back_ps(b_list, temp_b);
	printf("rr\n");
}

void	rra(t_node **a_list)
{
	t_node	*second_last;
	t_node	*last;

	second_last = NULL;
	last = *a_list;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	ft_lstadd_front_ps(a_list, last);
	ft_printf("rra\n");
}

void	rrb(t_node **b_list)
{
	t_node	*second_last;
	t_node	*last;

	second_last = NULL;
	last = *b_list;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	ft_lstadd_front_ps(b_list, last);
	ft_printf("rrb\n");
}
