/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:58:02 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/27 07:41:22 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_target_alignment(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	if (node->above_medium == 1 && node->target->above_medium == 1)
	{
		if (node->index < node->target->index)
			node->moves_to_top -= node->index;
		else
			node->moves_to_top -= node->target->index;
	}
	else if (node->above_medium == 0 && node->target->above_medium == 0)
	{
		if (count_nodes(stack_a) - node->index < count_nodes(stack_b) - node->target->index)
			node->moves_to_top -= count_nodes(stack_a) - node->index;
		else
			node->moves_to_top -= count_nodes(stack_b) - node->target->index;
	}
}

void	count_move_cost(t_stack **stack_a, t_stack **stack_b)
{
	int size_a;
	int	size_b;
	t_stack *temp;

	size_a = count_nodes(stack_a);
	size_b = count_nodes(stack_b);
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->above_medium == 0)
			temp->moves_to_top = size_a - (temp->index);
		else
			temp->moves_to_top = temp->index;
		if (temp->target->above_medium == 1)
			temp->moves_to_top += temp->target->index;
		else
			temp->moves_to_top += size_b - (temp->target->index);
		calculate_target_alignment(stack_a, stack_b, temp);
		temp = temp->next;
	}
}

t_stack *less_moves_top(t_stack **stack_a)
{
	t_stack	*temp_a;
	t_stack	*selected_node;
	int		minimum_moves;

	temp_a = *stack_a;
	selected_node = NULL;
	minimum_moves = INT_MAX;
	while (temp_a)
	{
		if (temp_a->moves_to_top > minimum_moves)
		{
			minimum_moves = temp_a->moves_to_top;
			selected_node = temp_a;
		}
		temp_a = temp_a->next;
	}
	return (selected_node);
}
