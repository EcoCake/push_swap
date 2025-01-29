/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:19:32 by amezoe            #+#    #+#             */
/*   Updated: 2025/01/29 11:30:09 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_item(int value)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->moves_to_top = 0;
	new->above_medium = 0;
	new->next = NULL;
	new->target = NULL;
	return (new);
}
void free_list(t_stack *head)
{
	t_stack	*current;
	t_stack *next;
	
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}