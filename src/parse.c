/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:39:26 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/05 12:38:52 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_format(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		if (av[i][0] == '\0')
			return (0);
		if (!(ft_isdigit(av[i][j]) 
			|| (av[i][j] == '-' && ft_isdigit(av[i][j + 1]))))
			return (0);
		j++;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j])))
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
    int	i, j;
    int	*num_values;
    int	num_value;

    int size = ft_arg_count(num);
    num_values = (int *)malloc(sizeof(int) * size);
    if (!num_values)
        return (0);
    
    for (i = 0; i < size; i++)
	{
		num_value = ft_atoi(num[i]);
		num_values[i] = num_value;
		for (j = 0; j < i; j++)
        {
            if (num_values[j] == num_value)
            {
                free(num_values);
                return (0);
            }
        }
    }
    free(num_values);
    return (1);
}


// int	check_dupe(char **num)
// {
// 	int	i;
// 	int	j;
// 	int	*num_values;
// 	int	num_value;

// 	i = -1;
// 	j = 0;
// 	num_values = (int *)malloc(sizeof(int) * ft_arg_count(num));
// 	while (num[++i] != NULL)
// 	{
// 		num_value = atoi(num[i]);
// 		num_values[i] = num_value;
// 		j = 0;
// 		while (j < 1)
// 		{
// 			if (num_values[j] == num_value)
// 			{
// 				free(num_values);
// 				return (0);
// 			}
// 			j++;
// 		}
// 	}
// 	free(num_values);
// 	return (1);
// }

int	validate_input(char** av)
{


    if (!validate_format(av))
        return (0);
    if (!check_dupe(av))
        return (0);
    if (!validate_num_limit(av))
      return (0);
    return (1);
}


// int	validate_input(char**av)
// {
// 	if (!(validate_format(av)) || !(check_dupe(av))
// 		|| !(validate_num_limit(av)))
// 		return (0);
// 	return (1);
// }

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
