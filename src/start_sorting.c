/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:29:56 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/28 13:23:38 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_sorting(t_node **a_list, t_node **b_list, int size_a)
{
	if (size_a == 2)
		sort_size_2(a_list);
	if (size_a == 3)
		sort_size_3(a_list);
	b_list = NULL;
}

void	sort_size_2(t_node **a_list)
{
	if (((*a_list)->data) > ((*a_list)->next->data))
		sa(a_list);
}

void	sort_size_3(t_node **a_list)
{
	int	first;
	int	second;
	int	third;

	first = (*a_list)->data;
	second = (*a_list)->next->data;
	third = (*a_list)->next->next->data;
	if (first < second && second > third && first < third)
	{
		rra(a_list);
		sa(a_list);
	}
	else if (first < second && second > third && first > third)
		rra(a_list);
	else if (first > second && second < third && first < third)
		sa(a_list);
	else if (first > second && second < third && first > third)
		ra(a_list);
	else if (first > second && second > third && first > third)
	{
		ra (a_list);
		sa(a_list);
	}
    printf("Liste nach Operation:\n");

    t_node *temp = *a_list;
    while (temp != NULL)
    {
        printf("list danach: %d\n", temp->data);
        temp = temp->next;
    }
}
