/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:35:42 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/29 15:26:31 by ymauk            ###   ########.fr       */
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
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_vars
{
	int				min_a;
	int				max_a;
	int				max_b;
	int				min_b;
}	t_vars;

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
int		ft_lstsize_ps(t_node *lst);
void	ft_lstadd_front_ps(t_node **lst, t_node *new);
void	ft_min_max_a(t_node **lst, t_vars *sets);

//help_node2
void	ft_min_max_b(t_node **lst, t_vars *sets);

//checking_string
void	check_string(char **string);
void	no_ints(char **str);
void	duplicates(char **str);
void	size_int(char **str);

//error_handling
void	error_handling(char **str);

//operations
void	sa(t_node **a_list);
void	sb(t_node **b_list);
void	ss(t_node **a_list, t_node **b_list);
void	pa(t_node **to_a, t_node **from_b);
void	pb(t_node **to_b, t_node **from_a);

//operations2
void	ra(t_node **a_list);
void	rb(t_node **b_list);
void	rr(t_node **a_list, t_node **b_list);
void	rra(t_node **a_list);

//start_sorting
void	start_sorting(t_node **a_list, t_node **b_list, int size_a);
void	sort_size_2(t_node **_list);
void	sort_size_3(t_node **a_list);
void	main_sort(t_node **a_list, t_node **b_list);

//rotating
void	rotation(t_node **a_list, t_node **b_list, t_vars *sets);
int		find_closest_number(int a_value, t_node **b_list, t_vars *sets);

#endif