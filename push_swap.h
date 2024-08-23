/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:35:42 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/23 17:26:23 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

//colours

# define B "\033[0;34m"
# define P "\033[0;35m"
# define R "\033[0;31m"
# define G "\033[0;32m"
# define DC "\033[0;39m"
# define Y "\033[0;33m"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

//parsing
t_node	*parsing1(t_node *a_list, int argc, char **argv);
char	**parsing2(char **argv, int size);
char	**parsing3(int argc, char **argv);
int		allocate_and_copy(char **split_string, char **temp_split, int j);
t_node	*create_list(char **str, t_node *a_list);

//help
int		counting_size(int argc, char **argv);
long	ft_atol(const char *str);

//help_node
void	ft_lstadd_back_ps(t_node **lst, t_node *new);
t_node	*ft_lstnew_ps(int *content);

//checking_string
void	check_string(char **string);
void	no_ints(char **str);
void	duplicates(char **str);
void	size_int(char **str);

//error_handling
void	error_handling(char **str);

#endif