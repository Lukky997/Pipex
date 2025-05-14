/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 03:10:49 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 17:53:08 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_libft.h"

void	ft_putstr(char *str, int *i)
{
	char	*v_null;

	v_null = "(null)";
	if (!str)
	{
		while (*v_null)
		{
			ft_putchar(*v_null, i);
			v_null++;
		}
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str, i);
			str++;
		}
	}
}
