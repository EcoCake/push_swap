/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_top_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:34:04 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/07 13:51:33 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minimum_on_top(t_stack **stack)
{
	t_stack	*lowest_node;
	int		index_of_lowest;
	int		sizeof_stack;
	int		times;

	lowest_node = find_lower(stack);
	index_of_lowest = lowest_node->index;
	sizeof_stack = count_nodes(stack);
	times = sizeof_stack - index_of_lowest;
	while (lowest_node->above_medium == 1 && index_of_lowest > 0)
	{
		rotate_a(stack, 0);
		index_of_lowest--;
	}
	while (lowest_node->above_medium == 0 && times > 0)
	{
		rev_rotate_a(stack, 0);
		times--;
	}
}

void	maximum_on_top(t_stack **stack)
{
	t_stack	*highest_node;
	int		index_of_max;
	int		sizeof_stack;
	int		times;

	if (stack == NULL || *stack == NULL)
		return ;
	highest_node = find_bigger(stack);
	if (highest_node == NULL)
		return ;
	index_of_max = highest_node->index;
	sizeof_stack = count_nodes(stack);
	times = sizeof_stack - index_of_max;
	while (highest_node->above_medium == 1 && index_of_max > 0)
	{
		rotate_b(stack, 0);
		index_of_max--;
	}
	while (highest_node->above_medium == 0 && times > 0)
	{
		rev_rotate_b(stack, 0);
		times--;
	}
}
