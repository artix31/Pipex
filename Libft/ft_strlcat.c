/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 07:22:32 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/10 05:42:59 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	dstsize;
	size_t	i;

	i = 0;
	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	if (!src || !dst || size == 0)
		return (srcsize);
	if (dstsize >= size)
		return (size + srcsize);
	while (src[i] && (dstsize + i) < (size - 1))
	{
		dst[dstsize + i] = src[i];
		i++;
	}
	dst[dstsize + i] = '\0';
	return (dstsize + srcsize);
}
