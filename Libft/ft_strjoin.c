/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:58 by amashhad          #+#    #+#             */
/*   Updated: 2024/09/09 07:22:22 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	char	*joined;

	i = -1;
	joined = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char ));
	if (!joined)
		return (NULL);
	if (!str1)
		str1 = ft_strdup("");
	if (!str2)
		str2 = ft_strdup("");
	if (!str1 && !str2)
		return (NULL);
	while (str1[++i] != '\0')
		joined[i] = str1[i];
	i = -1;
	while (str2[++i] != '\0')
		joined[ft_strlen(str1) + i] = str2[i];
	return (joined);
}
