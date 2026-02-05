/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:07:15 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/02/05 14:07:18 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_next_word(char const *s, char c, int *cursor)
{
	char	*word;
	int		len;
	int		start;
	int		i;

	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	start = *cursor;
	while (s[*cursor] && s[*cursor] != c)
	{
		(*cursor)++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **res, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		cursor;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < words)
	{
		res[i] = get_next_word(s, c, &cursor);
		if (!res[i])
			return (free_all(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
