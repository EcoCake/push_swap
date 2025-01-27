/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:52:22 by amezoe            #+#    #+#             */
/*   Updated: 2024/12/10 17:50:49 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hexlength(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_hexprint(unsigned int numb, const char format)
{
	if (numb >= 16)
	{
		ft_hexprint(numb / 16, format);
		ft_hexprint(numb % 16, format);
	}
	else
	{
		if (numb < 10)
			ft_putchar(numb + '0');
		else
		{
			if (format == 'x')
				ft_putchar(numb - 10 + 'a');
			else
				ft_putchar(numb - 10 + 'A');
		}
	}
}

int	ft_hexput(unsigned int numb, const char type)
{
	if (numb == 0)
		return (ft_putchar('0'));
	else
		ft_hexprint(numb, type);
	return (ft_hexlength(numb));
}
