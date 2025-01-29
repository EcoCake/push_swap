/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:52:43 by amezoe            #+#    #+#             */
/*   Updated: 2025/01/29 11:39:52 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../printf/ft_printf.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int	value;
	int	index;
	int	moves_to_top;
	int	above_medium;

	struct s_stack *next;
	struct s_stack *target;
} t_stack;


int			validate_format(char **av);
int			validate_num_limit(char **num);
int			check_dupe(char **num);
long long	ft_atol(const char *nptr);
int			ft_arg_count(char **av);
void		error(void);
void free_list(t_stack *head);
t_stack *new_item(int value);
int	max_of_list(t_stack **stack);
int	min_of_list(t_stack **stack);


#endif