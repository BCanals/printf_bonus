/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:39:09 by becanals          #+#    #+#             */
/*   Updated: 2025/09/23 18:44:45 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size && src[i])
		dest[i] = src[i];
	if (size > 0)
	{
		if (i == size)
			dest[i - 1] = 0;
		else
			dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../C02/ex12/ft_print_memory.c"

void	checker(char *d, char *s, unsigned int len, int test);

int	main(void)
{
	checker("....", "aa", 0, 1);
	checker("....", "", 0, 1); 
	checker("....", "", 0, 2); 
	checker("....", "bb", 0, 3); 
	checker("....", "", 2, 4); 
	checker("....", "bb", 1, 5); 
	checker("....", "bb", 2, 6); 
	checker("....", "bb", 3, 7); 
	checker("....", "", 1, 8); 
	checker("....", "", 2, 9); 
	checker("....", "", 3, 10); 
	checker("....", "bb", 0, 11); 
	checker("....", "bb", 1, 12); 
	checker("....", "bb", 3, 14); 
	checker("....", "bb", 4, 15); 
	checker("....", "bb", 5, 16); 
	char *c = "aa";
	checker(c, c, 0, 17);
	checker(c, c, 1, 18);
	checker(c, c, 2, 19);
	checker(c, c, 3, 20);
	checker(c, c, 4, 21);
	checker(c, c, 5, 22);
}

void	checker(char *d, char *s, unsigned int len, int test)
{
	printf(" ------------------------------------------------------\n");
	printf("                   TEST NUMBER %i\n", test);
	printf(" ------------------------------------------------------\n");
	int				buffer_size = strlen(s) + strlen(d) + 1;
	char			*d1;
	char			*d2;
	unsigned long	r1;
	unsigned int	r2;

	d1 = calloc(sizeof(char), buffer_size);
	d2 = calloc(sizeof(char), buffer_size);
	if (!d1 || !d2)
		return ;
	//memset(d1, '.', buffer_size - 1);
	//memset(d2, '.', buffer_size - 1);
	strcpy(d1, d);
	strcpy(d2, d);
	printf("strings copied!\n");
	printf("\n === BEFORE ===\nsrc: %s\nstd: %s\nft_: %s\n",
		s, d1, d2);
	r1 = strlcpy(d1, s, len);
	printf("strlcpy ok!\n");
	r2 = ft_strlcpy(d2, s, len);
	printf("ft_strlcpy ok!!\n");
	printf("\n==>AFTER:\nsrc: %s\nstd: %lu - %s\nft_: %u - %s\n",
		s, r1, d1, r2, d2);
	printf("\n === MEMORY REGIONS AFTER ===\n");
	ft_print_memory(d1, buffer_size);
	ft_print_memory(d2, buffer_size);
	printf("\n\n");
}*/
