/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:24:14 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/02 18:48:48 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount0(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static char	**ft_mallocfinal(char **string, const char *s, char c)
{
	int	count;
	int	i;
	int	x;

	count = 0;
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == '\0'))
		{
			string[x] = (char *)malloc(sizeof(char) * (count + 1));
			if (!string[x])
				return (NULL);
			count = 0;
			x++;
		}
		i++;
	}
	return (string);
}

static char	**ft_wordcpy(char **string, const char *s, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
			string[x][y++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			string[x][y] = '\0';
		if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			string[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (string);
}

static char	**ft_free(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	free(string);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**string;
	int		wordcount;

	if (!s)
	{
		string = malloc(sizeof(char *) * 1);
		if (!string)
			return (NULL);
		*string = NULL;
		return (string);
	}
	wordcount = ft_wordcount0(s, c);
	string = (char **)malloc(sizeof(*string) * (wordcount + 1));
	if (!string)
		return (NULL);
	string = ft_mallocfinal(string, s, c);
	if (!string)
		ft_free(string);
	else
	{
		ft_wordcpy(string, s, c);
		string[wordcount] = NULL;
	}
	return (string);
}
