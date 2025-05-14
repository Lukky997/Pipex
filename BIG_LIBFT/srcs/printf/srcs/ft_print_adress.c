/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:32:13 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:52:41 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

void	calcul_hex(unsigned long long ptr, int *i)
{
	char	*hex_l;

	hex_l = "0123456789abcdef";
	if (ptr > 15)
		calcul_hex(ptr / 16, i);
	ft_putchar(hex_l[ptr % 16], i);
}

void	ft_print_adress(unsigned long long ptr, int *i)
{
	if (!ptr || ptr == 0)
		return (ft_putstr("(nil)", i));
	ft_putchar('0', i);
	ft_putchar('x', i);
	calcul_hex(ptr, i);
}
