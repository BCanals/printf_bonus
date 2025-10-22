/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:24:02 by becanals          #+#    #+#             */
/*   Updated: 2025/09/23 18:11:24 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dest[len] && len < nb)
		len++;
	dest += len;
	i = 0;
	if (!dest[i] && len < nb)
	{
		while (src[i] && len < (nb - 1))
		{
			dest[i] = src[i];
			len++;
			i++;
		}
		dest[i] = 0;
	}
	while (src[i++])
		len++;
	return (len);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../C02/ex12/ft_print_memory.c"

void	checker(char *s, char *d, unsigned int len, int test);

int	main(void)
{
	checker("", "", 0, 1); 
	checker("aa", "", 0, 2); 
	checker("", "bb", 0, 3); 
	checker("", "", 2, 4); 
	checker("", "bb", 1, 5); 
	checker("", "bb", 2, 6); 
	checker("", "bb", 3, 7); 
	checker("aa", "", 1, 8); 
	checker("aa", "", 2, 9); 
	checker("aa", "", 3, 10); 
	checker("aa", "bb", 0, 11); 
	checker("aa", "bb", 1, 12); 
	checker("aa", "bb", 2, 13); 
	checker("aa", "bb", 3, 14); 
	checker("aa", "bb", 4, 15); 
	checker("aa", "bb", 5, 16); 
	char *c = "aa";
	checker(c, c, 0, 17);
	checker(c, c, 1, 18);
	checker(c, c, 2, 19);
	checker(c, c, 3, 20);
	checker(c, c, 4, 21);
	checker(c, c, 5, 22);
}

void	checker(char *s, char *d, unsigned int len, int test)
{
	printf(" ------------------------------------------------------\n");
	printf("                   TEST NUMBER %i\n", test);
	printf(" ------------------------------------------------------\n");
	int				buffer_size = strlen(s) + strlen(d) + 1;
	char			*d1;
	char			*d2;

	d1 = calloc(sizeof(char), buffer_size);
	d2 = calloc(sizeof(char), buffer_size);
	if (!d1 || !d2)
		return ;
	//memset(d1, '.', buffer_size - 1);
	//memset(d2, '.', buffer_size - 1);
	strcpy(d1, d);
	strcpy(d2, d);
	printf("\n === BEFORE ===\nsrc: %s\nstd: %s\nft_: %s\n",
		s, d1, d2);
	printf("\n==>AFTER:\nsrc: %s\nstd: %lu - %s\nft_: %u - %s\n",
		s, strlcat(d1, s, len), d1, ft_strlcat(d2, s, len), d2);
	printf("\n === MEMORY REGIONS AFTER ===\n");
	ft_print_memory(d1, buffer_size);
	ft_print_memory(d2, buffer_size);
	printf("\n\n");
}*/
