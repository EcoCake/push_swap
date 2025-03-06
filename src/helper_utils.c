/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:24:13 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/04 13:41:00 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_count(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

long long	ft_atol(const char *nptr)
{
	long long	signal;
	long long	num;

	signal = 1;
	num = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		num *= 10;
		num += *nptr - 48;
		nptr++;
	}
	num *= signal;
	return (num);
}

void free_all(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a && *stack_a)
        free_list(*stack_a);
    if (stack_b && *stack_b)
        free_list(*stack_b);
}