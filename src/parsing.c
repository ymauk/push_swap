/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:42:42 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/23 12:47:13 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	allocate_and_copy(char **split_string, char **temp_split, int j)
{
	int	i;

	i = 0;
	while (temp_split[i] != NULL)
	{
		split_string[j] = ft_strdup(temp_split[i]);
		if (!split_string[j])
		{
			while (j > 0)
				free(split_string[--j]);
			free(split_string);
			while (temp_split[i] != NULL)
				free(temp_split[i++]);
			free(temp_split);
			return (-1);
		}
		j++;
		i++;
	}
	return (j);
}

char	**parsing3(int argc, char **argv)
{
	char	**split_string;
	char	**temp_split;
	int		i;
	int		j;

	split_string = (char **)malloc(((argc - 1) + 1) * sizeof(char *));
	if (!split_string)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		temp_split = ft_split(argv[i++], ' ');
		if (!temp_split)
			return (free(split_string), NULL);
		j = allocate_and_copy(split_string, temp_split, j);
		if (j == -1)
			return (NULL);
		free(temp_split);
	}
	split_string[j] = NULL;
	return (split_string);
}

char	**parsing2(char **argv, int size)
{
	char	**split_string;

	split_string = (char **)malloc((size + 1) * sizeof(char *));
	if (!split_string)
		return (NULL);
	split_string = ft_split(argv[1], ' ');
	split_string[size] = NULL;
	return (split_string);
}

// if (argc == 2 && ft_strchr(argv[1], ' ') -> is used if argument is in ""
// else if (argc > 2)               -> is used by multiple singel arguments

void	parsing1(t_node *a_list, int argc, char **argv)
{
	char	**string;
	int		size;
	a_list = NULL;

	size = counting_size(argc, argv);
	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
		string = parsing2(argv, size);
	else if (argc > 2)
		string = parsing3(argc, argv);
	else
		exit(0);
	check_string(string);
	// return (*a_list);
}
