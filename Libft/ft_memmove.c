/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 03:12:42 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/05 00:34:42 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*t1;
	unsigned const char	*t2;

	t1 = dst;
	t2 = src;
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	if (src < dst)
	{
		while (n > 0)
		{
			t1[n - 1] = t2[n - 1];
			n--;
		}
	}
	return (dst);
}
