/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:29:56 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/28 17:49:26 by ymauk            ###   ########.fr       */
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
		ra (a_list);
		sa(a_list);
	}
}

void	main_sort(t_node **a_list, t_node **b_list)
{
	t_vars	sets;

	ft_min_max_a(a_list, &sets);
	pb(b_list, a_list);
	pb(b_list, a_list);
	pb(b_list, a_list);
	printf("Liste a_list:\n");
    t_node *temp = *a_list;
    while (temp != NULL)
    {
        printf("a_list: %d\n", temp->data);
        temp = temp->next;
    }
	printf("Liste b_list:\n");
	t_node *temp_b = *b_list;
    while (temp_b != NULL)
    {
        printf("b_list: %d\n", temp_b->data);
        temp_b = temp_b->next;
    }
	int	nbr = find_closest_number(a_list, b_list, &sets);
	printf("closest number: %d\n", nbr);
}

int	find_closest_number(t_node **a_list, t_node **b_list, t_vars *sets)
{
	int		min_delta;
	int		closest_number;
	t_node	*temp_b;

	temp_b = *b_list;
	closest_number = -1;
	min_delta = INT_MAX;
	while (temp_b != NULL)
	{
		ft_min_max_b(&temp_b, sets);
		if (temp_b->data == sets->min_a)
			closest_number = sets->max_b;
		else if (temp_b->data < (*a_list)->data)
		{
			if (((*a_list)->data - temp_b->data) < min_delta)
			{
				min_delta = ((*a_list)->data - temp_b->data);
				closest_number = temp_b->data;
			}
		}
		temp_b = temp_b->next;
	}
	return (closest_number);
}
