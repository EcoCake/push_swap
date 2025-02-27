/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:44:27 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/27 09:31:34 by amezoe           ###   ########.fr       */
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

