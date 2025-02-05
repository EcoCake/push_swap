/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:21:01 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/05 10:32:31 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_stack **stack_a, int flag)
{
	t_stack *current;
	t_stack *first_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first_node = *stack_a;
	current = first_node->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_a;
	*stack_a = first_node->next;
	first_node->next = NULL;
}

void rotate_b(t_stack **stack_b, int flag)
{
	t_stack *current;
	t_stack *first_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first_node = *stack_b;
	current = first_node->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_b;
	*stack_b = first_node->next;
	first_node->next = NULL;
}

void rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
}
