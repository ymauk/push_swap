/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:45 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/28 12:16:25 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a_list;
	t_node	*b_list;

	a_list = NULL;
	b_list = NULL;
	if (argc <= 1)
		return (ft_printf("%sWrong amount of arguments!\n%s", R, DC));
	a_list = parsing1(a_list, argc, argv);
	printf("Liste a_list:\n\n");
	t_node *temp = a_list;
	while (temp != NULL)
	{
		printf("list: %d\n", temp->data);
		temp = temp->next;
	}
	start_sorting(&a_list, &b_list, ft_lstsize_ps(a_list));
	return (0);
}
