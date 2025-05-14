/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:00:57 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:52:48 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

static void	count_char(va_list args, char c, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), i);
	if (c == 'p')
		ft_print_adress((unsigned long long) va_arg(args, void *), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, int), i);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", i);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", i);
	else if (c == '%')
		ft_putchar('%', i);
	else
	{
		ft_putchar('%', i);
		ft_putchar(c, i);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;

	index = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count_char(args, *format, &index);
			format++;
		}
		else
		{
			write(1, format++, 1);
			index++;
		}
	}
	va_end(args);
	return (index);
}
