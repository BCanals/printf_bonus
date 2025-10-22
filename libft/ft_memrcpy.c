/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:19:27 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 16:12:53 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *d, const void *s, size_t n)
{
	size_t	i;

	i = n;
	while (i--)
		((char *)d)[i] = ((char *)s)[i];
	return (d);
}
/*
#include <stdio.h>

int main(void)
{
	char s[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	char *ret;

	ret = ft_memrcpy(s, s + 1, 2);
	printf("%s\n%p => %p\n", s, s, ret);
}*/
