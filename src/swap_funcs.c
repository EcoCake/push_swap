/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:40:47 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/07 13:52:02 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a, int flag)
{
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (flag == 0)
		ft_printf("sa\n");
	if (flag == 2)
		ft_printf("sa\n");
	return ;
}

void	swap_b(t_stack **stack_b, int flag)
{
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (flag == 0)
		ft_printf("sb\n");
	if (flag == 2)
		ft_printf("sb\n");
	return ;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	ft_printf("ss\n");
	return ;
}
