/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:44:27 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/03 14:50:34 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack *current_stack;
	current_stack = *stack;
	while (current_stack && current_stack->next)
	{
		if (current_stack->value > current_stack->next->value)
			return (0);
		else
			current_stack = current_stack->next;
	}
	return (1);
}
void	sort_three(t_stack **stack)
{
	if (max_of_list(stack) == (*stack)->value && min_of_list(stack) == (*stack)->next->next->value)
	{
		swap_a(stack, 0);
		rev_rotate_a(stack, 0);
	}
	else if (max_of_list(stack) == (*stack)->next->value && min_of_list(stack) == (*stack)->value)
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
	else if (max_of_list(stack) == (*stack)->next->next->value)
		swap_a(stack, 0);
	else if (min_of_list(stack) == (*stack)->next->next->value)
		rev_rotate_a(stack, 0);
	else
		rotate_a(stack, 0);
}
void	less_moves_top_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *least_moves;

	if((*stack_a) == NULL)
		return ;
	least_moves = less_moves_top(stack_a);
	if (least_moves->above_medium == 1
		&& least_moves->target->above_medium == 1)
			rotate_ab_both(stack_a, stack_b, least_moves);
	else if (least_moves->above_medium == 0
			&& least_moves->target->above_medium == 0)
				rev_rotate_both(stack_a, stack_b, least_moves);
	add_top_a(stack_a, least_moves);
	add_top_b(stack_b,least_moves->target);
	push_b(stack_a, stack_b);
}

void	turks_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	sizeof_stack;

	update_b(stack_a, stack_b);
	sizeof_stack = count_nodes(stack_a);
	while(sizeof_stack-- > 3 && !is_sorted(stack_a))
	{
		index_def(stack_b);
		update_a(stack_a, stack_b);
		less_moves_top_b(stack_a, stack_b);
	}
	update_b(stack_a, stack_b);
	maximum_on_top(stack_b);
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	if (!is_sorted(stack_a) && sizeof_stack == 2)
		swap_a(stack_a, 0);
	while ((*stack_b) != NULL)
	{
		index_def(stack_a);
		update_b(stack_a,stack_b);
		add_top_a(stack_a, (*stack_b)->target);
		push_a(stack_a,stack_b);
	}
	index_def(stack_a);
	minimum_on_top(stack_a);
}
void	main_sorting(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		node_count_a;
	
	stack_b = NULL;
	node_count_a = count_nodes(stack_a);
	if (node_count_a == 2)
		swap_a(stack_a, 0);
	else if (node_count_a == 3)
		sort_three(stack_a);
	else if(node_count_a > 3)
	{
		if (count_nodes(stack_a) > 3)
			push_b(stack_a, &stack_b);
		if (count_nodes(stack_a) > 3)
			push_b(stack_a, &stack_b);
		turks_algo(stack_a, &stack_b);
	}
	free_list(stack_b);
}