/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:33:39 by amezoe            #+#    #+#             */
/*   Updated: 2025/02/04 10:38:21 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnumb(int n);
int		ft_hexlength(unsigned int n);
void	ft_hexprint(unsigned int numb, const char format);
int		ft_hexput(unsigned int numb, const char type);
int		ft_pointercount(unsigned long long n);
int		ft_pointerprint(unsigned long long n);
int		ft_pointerput(unsigned long long n);
int		ft_numblength(unsigned int n);
char	*ft_utoa(unsigned int n);
int		ft_unsignedput(unsigned int n);
int		ft_printf_args(va_list args, const char format);
int		ft_printf(const char *format, ...);

#endif