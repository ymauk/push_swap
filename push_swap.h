/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:35:42 by ymauk             #+#    #+#             */
/*   Updated: 2024/08/21 15:06:45 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/Libft/libft.h"
# include "lib/printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
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
	struct s_node	*next;
}	t_node;

//parsing
t_node	parsing1(t_node *a_list, int argc, char **argv);
char	**parsing2(int argc, char **argv);
char	**parsing3(int argc, char **argv);

//help
int		counting_size(int argc, char **argv);

#endif