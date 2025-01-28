/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:36:46 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/10 03:04:25 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	ch = c;
	i = ft_strlen(s);
	if (!ch)
		return ((char *)(s) + i);
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)(s) + i);
		i--;
	}
	if (s[0] == ch)
		return ((char *)(s) + i);
	return (0);
}
