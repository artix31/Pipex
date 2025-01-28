/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:18:00 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/05 00:39:37 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;

	x = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == x)
		{
			return ((unsigned char *)s + i);
		}
		i++;
	}
	return (NULL);
}
