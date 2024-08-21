/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:42:42 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/21 15:44:27 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**parsing3(int argc, char **argv)
{
	char	**split_string;
	int		i;
	int		j;
	int		k;
	char	**temp_split;

	i = 1;
	split_string = (char **)malloc(((argc - 1) + 1) * sizeof(char *));
	if (!split_string)
		return (NULL);
	j = 0;
	while (i < argc)
	{
		temp_split = ft_split(argv[i], ' ');
		k = 0;
		while (temp_split[k] != NULL)
			split_string[j++] = temp_split[k++];
		free(temp_split);
		i++;
	}
	split_string[j] = NULL;
	return (split_string);
}

char	**parsing2(int argc, char **argv)
{
	char	**split_string;
	int		size;

	size = counting_size(argc, argv);
	split_string = (char **)malloc((size + 1) * sizeof(char *));
	if (!split_string)
		return (NULL);
	split_string = ft_split(argv[1], ' ');
	split_string[size + 1] = NULL;
	return (split_string);
}

t_node	parsing1(t_node *a_list, int argc, char **argv)
{
	char	**string;
	a_list = NULL;

	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
		string = parsing2(argc, argv);
	else if (argc > 2)
		string = parsing3(argc, argv);
	else
		exit(0);
	printf("%s\n", string[0]);
	printf("%s\n", string[1]);
	printf("%s\n", string[2]);
	printf("%s\n", string[3]);
	printf("%s\n", string[4]);
	printf("%s\n", string[5]);
	return (*a_list);
}
