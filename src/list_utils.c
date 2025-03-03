/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:19:32 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/03 18:50:37 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_item(int value)
{
	t_stack	*new;

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

void	free_list(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	add_to_end(t_stack **list, t_stack *new)
{
	t_stack *temp;
	if (!list || !new)
		return;
	temp = *list;
	if(!temp)
		*list = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
int count_nodes(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return(i);
}

int	free_everything(char **str)
{
	int	i;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

//#include <stdio.h>
// int main (void)
// {
// 	t_stack *stack = NULL;
// 	t_stack *node;
	
// 	int i = 1;
// 	while (i <= 12)
// 	{
// 		node = new_item(i);
// 		add_to_end(&stack, node);
// 		i++;
// 	}
// 	printf("VERIFY SORTING => %i", count_nodes(&stack));
// } 
