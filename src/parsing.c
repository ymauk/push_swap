/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:42:42 by ymauk             #+#    #+#             */
/*   Updated: 2024/09/06 11:07:51 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**parsing3(char **split_string, char **string, int	*j)
{
	int	i;

	i = 0;
	while (split_string[i] != NULL)
	{
		string[*j] = ft_strdup(split_string[i]);
		(*j)++;
		i++;
	}
	return (split_string);
}

char	**parsing2(char **argv, int argc)
{
	char	**split_string;
	char	**string;
	int		size;
	int		i;
	int		j;

	i = 1;
	j = 0;
	size = counting_size(argv, argc);
	string = (char **) malloc((size + 1) * sizeof(char *));
	string[size] = NULL;
	while (i < argc)
	{
		split_string = ft_split(argv[i], ' ');
		parsing3(split_string, string, &j);
		i++;
		free (split_string);
	}
	i = 0;
	return (string);
}

t_node	*create_list(char **str, t_node *a_list)
{
	int		*nbr;
	t_node	*new_node;
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		nbr = (int *)malloc(sizeof(int));
		*nbr = ft_atoi(str[i]);
		new_node = ft_lstnew_ps(nbr);
		free (nbr);
		if (new_node)
			ft_lstadd_back_ps(&a_list, new_node);
		i++;
	}
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (a_list);
}

t_node	*parsing1(t_node *a_list, int argc, char **argv)
{
	char	**string;

	string = parsing2(argv, argc);
	check_string(string);
	return (create_list(string, a_list));
}
