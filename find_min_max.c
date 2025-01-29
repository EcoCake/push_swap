/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:33:17 by amezoe            #+#    #+#             */
/*   Updated: 2025/01/29 11:39:00 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_of_list(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	if(!*stack)
		return(-1);
	tmp = *stack;
	max = tmp->value;
	while(tmp != NULL)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
int	min_of_list(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	if(!*stack)
		return(-1);
	tmp = *stack;
	min = tmp->value;
	while(tmp != NULL)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}