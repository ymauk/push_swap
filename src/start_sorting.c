/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:29:56 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/29 15:54:31 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_sorting(t_node **a_list, t_node **b_list, int size_a)
{
	if (size_a == 2)
		sort_size_2(a_list);
	else if (size_a == 3)
		sort_size_3(a_list);
	else
		main_sort(a_list, b_list);
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
		ra(a_list);
		sa(a_list);
	}
}

void	main_sort(t_node **a_list, t_node **b_list)
{
	t_vars	sets;

	ft_min_max_a(a_list, &sets);
	pb(b_list, a_list);
	pb(b_list, a_list);
	rotation(a_list, b_list, &sets);
	printf("Liste a_list nach operation:\n");
	t_node *temp = *a_list;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("Liste b_list nach operation:\n");
	t_node *temp_b = *b_list;
	while (temp_b != NULL)
	{
		printf("%d\n", temp_b->data);
		temp_b = temp_b->next;
	}
}
