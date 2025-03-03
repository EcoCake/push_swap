/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_top_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:34:04 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/03 17:44:55 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_top_a(t_stack **stack_a, t_stack *node)
{
	while ((*stack_a)->value != node->value)
	{
		if (node->above_medium == 1)
			rotate_a(stack_a, 0);
		else
			rev_rotate_a(stack_a, 0);
	}
}

void add_top_b(t_stack **stack_b, t_stack *node)
{
	while ((*stack_b)->value != node->value)
	{
		if (node->above_medium == 1)
			rotate_b(stack_b, 0);
		else
			rev_rotate_b(stack_b, 0);
	}
}

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
	while(lowest_node->above_medium == 1 && index_of_lowest > 0)
	{
		rotate_a(stack, 0);
		index_of_lowest--;
	}
	while(lowest_node->above_medium == 0 && times > 0)
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

	highest_node = find_bigger(stack);
	index_of_max = highest_node->index;
	sizeof_stack = count_nodes(stack);
	times = sizeof_stack - index_of_max;

	while(highest_node->above_medium == 1 && index_of_max > 0)
	{
		rotate_b(stack, 0);
		index_of_max--;
	}
	while(highest_node->above_medium == 0 && times > 0)
	{
		rev_rotate_b(stack, 0);
		times--;
	}
}