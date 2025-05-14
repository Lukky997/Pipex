/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:51:56 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:02 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

static void	print_nb(long nb, int *i)
{
	if (nb / 10)
	{
		print_nb(nb / 10, i);
		print_nb(nb % 10, i);
	}
	else
		ft_putchar(nb + '0', i);
}

void	ft_putnbr(int n, int *i)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', i);
		nb = -nb;
	}
	print_nb(nb, i);
}
