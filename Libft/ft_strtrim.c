/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:36:07 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/10 07:18:10 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_firstpart(char const *s1, char const *set)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (set[c] && s1[i])
	{
		if (set[c] == s1[i])
		{
			i++;
			c = 0;
		}
		else
		{
			c++;
		}
	}
	return (i);
}

static	size_t	ft_lastpart(char const *s1, char const *set)
{
	size_t	i;
	size_t	c;

	i = ft_strlen(s1) - 1;
	c = 0;
	while (set[c] && i)
	{
		if (set[c] == s1[i])
		{
			i--;
			c = 0;
		}
		else
		{
			c++;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	p1;
	size_t	p2;
	size_t	i;
	char	*trim;

	p1 = ft_firstpart (s1, set);
	p2 = 1 + ft_lastpart (s1, set);
	i = 0;
	if (p2 < p1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(""));
	trim = malloc(sizeof(char) * ((p2 - p1) + 1));
	if (!trim)
		return (NULL);
	while ((p2 - p1) != 0)
	{
		trim[i] = s1[p1];
		p1++;
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
