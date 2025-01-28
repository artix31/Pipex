/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:12:45 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/13 01:27:27 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_conversion(long int n, char *number, int sign, size_t size)
{
	size_t	ssize;
	size_t	i;

	ssize = size;
	i = 0;
	if (sign == 1)
	{
		i = 1;
		number[0] = '-';
		size = size + 1;
	}
	while (i < size)
	{
		number [size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	if (sign == 1)
		number[ssize + 1] = '\0';
	else
		number[ssize] = '\0';
	return (number);
}

static	size_t	ft_sizecheck(long int n)
{
	size_t	i;
	size_t	numb;

	i = 0;
	numb = n;
	while (numb > 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*number;
	int			sign;
	size_t		size;

	num = n;
	sign = 0;
	if (num == 0)
	{
		number = ft_strdup("0");
		return (number);
	}
	if (num > 0)
		sign = 0;
	else
	{
		sign = 1;
		num = -num;
	}
	size = ft_sizecheck(num);
	number = malloc(sizeof(char) * size + 1 + sign);
	if (!number)
		return (NULL);
	number = ft_conversion(num, number, sign, size);
	return (number);
}
