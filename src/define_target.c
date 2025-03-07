/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:46:22 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/07 13:44:47 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_def(t_stack **stack)
{
	t_stack	*temp;
	int		size_of_list;
	int		new_index;

	size_of_list = count_nodes(stack);
	temp = *stack;
	new_index = 0;
	while (temp != NULL)
	{
		if (new_index > size_of_list / 2)
			temp->above_medium = 0;
		else
			temp->above_medium = 1;
		temp->index = new_index;
		new_index++;
		temp = temp->next;
	}
}

void	define_lowest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	long	lowest;

	temp_a = *stack_a;
	while (temp_a != NULL)
	{
		temp_b = *stack_b;
		lowest = LONG_MIN;
		while (temp_b != NULL)
		{
			if (temp_a->value > temp_b->value && lowest < temp_b->value)
			{
				lowest = temp_b->value;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (lowest == LONG_MIN)
			temp_a->target = find_bigger(stack_b);
		temp_a = temp_a->next;
	}
}

void	define_highest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*temp_b;
	long	highest;

	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		current_a = *stack_a;
		highest = LONG_MAX;
		while (current_a != NULL)
		{
			if (current_a->value > temp_b->value && highest > current_a->value)
			{
				highest = current_a->value;
				temp_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (highest == LONG_MAX)
			temp_b->target = find_lower(stack_a);
		temp_b = temp_b->next;
	}
}

void	update_a(t_stack **stack_a, t_stack **stack_b)
{
	index_def(stack_a);
	define_lowest(stack_a, stack_b);
	count_move_cost(stack_a, stack_b);
}

void	update_b(t_stack **stack_a, t_stack **stack_b)
{
	index_def(stack_b);
	define_highest(stack_a, stack_b);
}
