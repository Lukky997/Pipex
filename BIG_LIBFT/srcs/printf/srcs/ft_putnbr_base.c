/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:26:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 18:00:25 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

static int	verif_conditions_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *i)
{
	int		len_base;
	long	long_nbr;

	long_nbr = nbr;
	len_base = ft_strlen(base);
	if (verif_conditions_base(base))
	{
		if (long_nbr >= len_base)
		{
			ft_putnbr_base(long_nbr / len_base, base, i);
			ft_putchar(base[long_nbr % len_base], i);
		}
		else
			ft_putchar(base[long_nbr % len_base], i);
	}
}
