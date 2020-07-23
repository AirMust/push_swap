/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:19:50 by slynell           #+#    #+#             */
/*   Updated: 2019/09/14 15:19:51 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t		i;
	size_t		words;

	words = 0;
	i = 0;
	if (s == NULL || *s == 0)
		return (0);
	while (*s != 0)
	{
		while (*s != 0 && *s == c)
			s++;
		if (!*s)
			break ;
		words++;
		while (*s != c && *s != 0)
			s++;
	}
	return (words);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

static char		**words(char const **s, char c, char **result, size_t *word)
{
	size_t		i;

	result[*word] = (char *)malloc(word_len(*s, c) + 1);
	if (result[*word] == NULL)
	{
		while (*word-- > 0)
			free(result[*word]);
		free(result);
		return (NULL);
	}
	i = 0;
	while (**s != c && **s != 0)
	{
		result[*word][i++] = **s;
		(*s)++;
	}
	result[*word][i] = 0;
	*word = *word + 1;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	size_t		words_cnt;
	size_t		word;

	words_cnt = count_words(s, c);
	if (s == NULL || sizeof(char *) * words_cnt + 1 == 0)
		return (NULL);
	if ((result = (char **)malloc(sizeof(char *) * words_cnt + 1)) == NULL)
		return (NULL);
	result[words_cnt] = NULL;
	word = 0;
	while (s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		if ((result = words(&s, c, result, &word)) == NULL)
			return (NULL);
		if (*s != '\0')
			s++;
	}
	if (words_cnt == 0)
		result[0] = NULL;
	return (result);
}
