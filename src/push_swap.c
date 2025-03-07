/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:52:46 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/07 13:59:45 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = av + 1;
	if (validate_input(av) == 1)
	{
		stack_a = stack_initialization(av);
		if (is_sorted(&stack_a) == 0)
		{
			main_sorting(&stack_a);
			free_list(stack_a);
		}
		else
			free_list(stack_a);
	}
	else
		ft_printf("Error\n");
	if (ac == 2)
		free_everything(av);
	return (0);
}
