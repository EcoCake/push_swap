/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:05:38 by amezoe            #+#    #+#             */
/*   Updated: 2024/12/10 17:51:58 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pointercount(unsigned long long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

int	ft_pointerprint(unsigned long long n)
{
	if (n >= 16)
	{
		ft_pointerprint(n / 16);
		ft_pointerprint(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n - 10 + 'a');
	}
	return (ft_pointercount(n));
}

int	ft_pointerput(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len = write(1, "0x", 2);
	len += ft_pointerprint(n);
	return (len);
}
