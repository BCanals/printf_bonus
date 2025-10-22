/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:43:13 by becanals          #+#    #+#             */
/*   Updated: 2025/09/30 18:44:53 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	**ft_clean(char **array)
{
	size_t	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**rtrn;
	size_t	i;
	size_t	j;

	rtrn = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!rtrn)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			rtrn[j] = ft_strndup((char *)&s[i], word_len(&s[i], c));
			if (!rtrn[j])
				return (ft_clean(rtrn));
			j++;
			i += word_len(&s[i], c);
		}
	}
	return (rtrn);
}
/*
#include <stdio.h>

int main(void)
{
	char	*s = "Hello world u";
	char	c = ' ';
	char	**array = ft_split(s, c);
	int		i = 0;
	
	printf("array: %p\n", array);
	while (i < 4)
	{
		printf("array[%i]: %p\n", i, array[i]);
		i++;
	}
	i = 0;	
	printf("array[%i]: %p\n", i, array[i]);
	while (array[i])
	{
		printf("%s\n", array[i]);
		i ++;
		printf("array[%i]: %p\n", i, array[i]);
		//free(array[i]);
	}
	//free(array);
}*/
