/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:39:26 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/03 11:19:17 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_format(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_num_limit(char **num)
{
	int	i;

	i = 0;
	while (num[i] != NULL)
	{
		if (ft_atol(num[i]) > INT_MAX || ft_atol(num[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_dupe(char **num)
{
	int	i;
	int	j;
	int	*num_values;
	int	num_value;

	i = -1;
	j = 0;
	num_values = (int *)malloc(sizeof(int) * ft_arg_count(num));
	while (num[++i] != NULL)
	{
		num_value = atoi(num[i]);
		num_values[i] = num_value;
		j = 0;
		while (j < 1)
		{
			if (num_values[j] == num_value)
			{
				free(num_values);
				return (0);
			}
			j++;
		}
	}
	free(num_values);
	return (1);
}

int	validate_input(char**av)
{
	if (!(validate_format(av)) || !(check_dupe(av))
		|| !(validate_num_limit(av)))
		return (0);
	return (1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
