/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:29:35 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 16:24:42 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (str[i] == chr)
			return ((void *)&str[i]);
	return (NULL);
}
/*
#include <stdio.h>

int main (void)
{
	char	str[] = {0, 1, 2 ,3 ,3 ,5};
	//char	c = 'c';

	printf("str: %p\nret: %p\n", str, ft_memchr(str, 0, 1));
}*/
