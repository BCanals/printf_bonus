/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:29:35 by becanals          #+#    #+#             */
/*   Updated: 2025/10/21 19:00:07 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memchr_pos(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (str[i] == chr)
			return (i);
	return (-1);
}
/*
#include <stdio.h>

int main (void)
{
	char	str[] = {0, 1, 2 ,3 ,3 ,5};
	//char	c = 'c';

	printf("str: %i\nret: %p\n", str, ft_memchr_pos(str, 0, 1));
}*/
