/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:03:27 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/07 14:38:10 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(const char **str, int a)
{
	while (a > 0)
	{
		a--;
		free((void *)str[a]);
	}
	free(str);
	return (NULL);
}

static char	*fill_word(const char *str, int a)
{
	int		i;
	char	*to_array;

	i = 0;
	to_array = (char *)malloc(sizeof(char) * (a + 1));
	if (!to_array)
	{
		return (NULL);
	}
	while (a)
	{
		to_array[i] = str[i];
		i++;
		a--;
	}
	to_array[i] = '\0';
	return (to_array);
}

static int	n_len(const char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
		}
		while (str[i] != c && str[i])
		{
			i++;
		}
		while (str[i] == c && str[i])
		{
			i++;
		}
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		word;
	int		len;
	char	**array;

	i = 0;
	word = count_words(str, c);
	array = (char **)malloc(sizeof(char *) * (word + 1));
	if (!array)
		return (NULL);
	while (word--)
	{
		while (*str && *str == c)
			str++;
		len = n_len(str, c);
		array[i] = fill_word((const char *)str, len);
		if (!array[i])
			return (free_array((const char **)array, i));
		i++;
		while (*str && *str != c)
			str++;
	}
	array[i] = (char *) '\0';
	return (array);
}
