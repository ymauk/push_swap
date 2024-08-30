/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:38:40 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/30 12:47:07 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//  new node at the end of the list
void	ft_lstadd_back_ps(t_node **lst, t_node *new)
{
	t_node	*ptr;

	ptr = *lst;
	if (lst == NULL)
		return ;
	if (ptr == 0)
	{
		*lst = new;
		return ;
	}
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}

//  new node at beginning of the list
void	ft_lstadd_front_ps(t_node **lst, t_node *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

// new node with the value content
t_node	*ft_lstnew_ps(int *content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = *content;
	new_node->next = NULL;
	return (new_node);
}

// number of elements in the list
int	ft_lstsize_ps(t_node *lst)
{
	int	size;

	size = 0;
	if (lst == 0)
		return (0);
	while (lst != 0)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// finding the min and max elenent of the list a
void	ft_min_max_a(t_node *lst, t_vars *sets)
{
	t_node	*temp;

	temp = lst;
	sets->max_a = temp->data;
	sets->min_a = temp->data;
	while (temp != NULL)
	{
		if (temp->data > sets->max_a)
			sets->max_a = temp->data;
		else if (temp->data < sets->min_a)
			sets->min_a = temp->data;
		temp = temp->next;
	}
}
