/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:05:57 by amashhad          #+#    #+#             */
/*   Updated: 2024/12/23 04:07:18 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*str;

	str = malloc(size);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, ptr, size);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
