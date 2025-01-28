/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putitox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:33:32 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/11 08:32:18 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static void	ft_convert(int n, char size)
{
	char	*convertl;
	char	*convertu;
	char	c;

	convertl = "0123456789abcdef";
	convertu = "0123456789ABCDEF";
	if (size == 'X')
	{
		c = convertu[n];
		write (1, &c, 1);
	}
	else
	{
		c = convertl[n];
		write (1, &c, 1);
	}
}

int	ft_putitox(unsigned int nb, char size)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = ft_count(nb);
	if (nb >= 16)
		ft_putitox(nb / 16, size);
	ft_convert((nb % 16), size);
	return (count);
}
