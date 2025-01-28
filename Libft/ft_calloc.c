/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:03:25 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/12 15:45:25 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmem, size_t size)
{
	char	*result;
	size_t	fullsize;
	size_t	i;

	i = 0;
	fullsize = nmem * size;
	result = (char *)malloc(fullsize);
	if (result == NULL)
		return (NULL);
	while (i < fullsize)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
