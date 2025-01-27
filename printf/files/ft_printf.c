/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:24:46 by amezoe            #+#    #+#             */
/*   Updated: 2024/12/10 17:52:58 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_args(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 'd')
		return (ft_putnumb(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_pointerput(va_arg(args, unsigned long long)));
	else if (format == 'u')
		return (ft_unsignedput(va_arg(args, unsigned int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnumb(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (ft_hexput(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_printf_args(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	printf ("Characters: %c %c \n", 'a', 65);
// 	printf ("Decimals: %d %ld\n", 1977, 650000L);
// 	printf ("Preceding with blanks: %10d \n", 1977);
// 	printf ("Preceding with zeros: %010d \n", 1977);
// 	printf ("Some different radices: %d %x %o \n", 100, 100, 100);
// 	printf ("Some different radices: %#x %#o \n", 100, 100);
// 	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
// 	printf ("Width trick: %*d \n", 5, 10);
// 	printf ("%s \n", "A string");

// 	ft_printf ("Characters: %c %c \n", 'a', 65);
// 	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
// 	ft_printf ("Preceding with blanks: %10d \n", 1977);
// 	ft_printf ("Preceding with zeros: %010d \n", 1977);
// 	ft_printf ("Some different radices: %d %x %o \n", 100, 100, 100);
// 	ft_printf ("Some different radices: %#x %#o \n", 100, 100);
// 	ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
// 	ft_printf ("Width trick: %*d \n", 5, 10);
// 	ft_printf ("%s \n", "A string");
// 	return 0;
// }