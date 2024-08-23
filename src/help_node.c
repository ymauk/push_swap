/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:38:40 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/23 17:27:06 by ymauk            ###   ########.fr       */
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

// new node with the value content
t_node	*ft_lstnew_ps(int *content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = *content;
	new_node->next = NULL;
	return (new_node);
}
