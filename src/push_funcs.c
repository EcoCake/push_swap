/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:45:38 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/03 18:48:46 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_first;
	t_stack	*b_first;

	if (*stack_a == NULL)
		return ;
	a_first = *stack_a;
	b_first = *stack_b;
	*stack_b = b_first->next;
	b_first->next = a_first;
	*stack_a = b_first;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_first;
	t_stack	*b_first;

	if (!stack_a || !*stack_a)
	return;
	if (*stack_b == NULL)
		return ;
	b_first = *stack_b;
	a_first = *stack_a;
	*stack_a = a_first->next;
	a_first->next = b_first;
	*stack_b = a_first;
	ft_printf("pb\n");
}
