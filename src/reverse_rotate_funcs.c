/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:15:04 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/03 14:18:28 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stack **stack_a, int flag)
{
	t_stack	*current;
	t_stack	*new_last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	current = *stack_a;
	new_last_node = NULL;
	while (current->next != NULL)
	{
		new_last_node = current;
		current = current->next;
	}
	new_last_node->next = NULL;
	current->next = *stack_a;
	*stack_a = current;
	if (flag == 0 || flag == 2)
		ft_printf("rra\n");
}

void	rev_rotate_b(t_stack **stack_b, int flag)
{
	t_stack	*current;
	t_stack	*new_last_node;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	current = *stack_b;
	new_last_node = NULL;
	while (current->next != NULL)
	{
		new_last_node = current;
		current = current->next;
	}
	new_last_node->next = NULL;
	current->next = *stack_b;
	*stack_b = current;
	if (flag == 0 || flag == 2)
		ft_printf("rrb\n");
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_a(stack_a, 1);
	rev_rotate_b(stack_b, 1);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while(*stack_a != node && *stack_b != node->target)
		rev_rotate_ab(stack_a, stack_b);
	index_def(stack_a);
	index_def(stack_b);
}
