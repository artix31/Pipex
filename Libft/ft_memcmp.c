/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:13:16 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/10 05:35:55 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*t1;
	const unsigned char	*t2;
	int					counter;

	t1 = s1;
	t2 = s2;
	i = 0;
	counter = 0;
	if (n == 0)
		return (0);
	while (t1[i] == t2[i] && i < n - 1)
	{
		i++;
	}
	counter = t1[i] - t2[i];
	return (counter);
}
