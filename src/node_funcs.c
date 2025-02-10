/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:07:19 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/10 16:33:59 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_initialization(char **av)
{
	t_stack *stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (av[i] != NULL)
	{
		new_node = new_item(ft_atol(av[i]));
		add_to_end(&stack, new_node);
		i++;
	}
	return(stack);
}

t_stack	*find_bigger(t_stack **stack)
{
	t_stack	*temp;
	int		biggest_val;
	t_stack	*bigger_node;

	temp = *stack;
	biggest_val = INT_MIN;
	bigger_node = NULL;
	while(temp != NULL)
	{
		if (temp->value > biggest_val)
		{
			biggest_val = temp->value;
			bigger_node = temp;
		}
		temp = temp->next;
	}
	return(bigger_node);
}

t_stack	*find_lower(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_val;
	t_stack	*lower_node;

	temp = *stack;
	lowest_val = INT_MAX;
	lower_node = NULL;
	while(temp != NULL)
	{
		if (temp->value < lowest_val)
		{
			lowest_val = temp->value;
			lower_node = temp;
		}
		temp = temp->next;
	}
	return(lower_node);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *test[] = {"1", "2", "3", NULL};
// 	t_stack *stack_test;

// 	stack_test = stack_initialization(test);
// 	while (stack_test != NULL)
// 	{
// 		t_stack *temp = stack_test->next;
// 		printf("%i\n", stack_test->value);
// 		free(stack_test);
// 		stack_test = temp;
// 	}
// 	return 0;
// }