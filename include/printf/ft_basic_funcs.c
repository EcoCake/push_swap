/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:00:53 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/03 18:00:32 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
size_t	ft_numb_len(int numb)
{
	int	len;

	len = 0;
	if (numb <= 0)
		len++;
	while (numb)
	{
		len++;
		numb = numb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	numb;

	len = ft_numb_len(n);
	numb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (numb < 0)
	{
		str[0] = '-';
		numb = -numb;
	}
	if (numb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (numb)
	{
		str[len] = numb % 10 + '0';
		len--;
		numb = numb / 10;
	}
	return (str);
}

int	ft_putnumb(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}


