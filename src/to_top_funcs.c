/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_top_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:34:04 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/19 06:38:48 by amezoe           ###   ########.fr       */
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