/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:34:06 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/11 08:32:30 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putllox(unsigned long long nb)
{
	char	*hex;
	char	buffer[16];
	int		i;
	int		count;

	hex = "0123456789abcdef";
	i = 0;
	if (nb == 0)
		buffer[i++] = '0';
	while (nb > 0)
	{
		buffer[i++] = hex[nb % 16];
		nb /= 16;
	}
	count = i;
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (count);
}

int	ft_putvoid(void *v)
{
	unsigned long long	x;
	int					count;

	x = (unsigned long long)v;
	if (!v)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	count += write(1, "0x", 2);
	count += ft_putllox(x);
	return (count);
}
