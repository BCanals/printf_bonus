/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:21 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 19:11:18 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	i = -1;
	while (++i < n && str1[i] == str2[i])
		;
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	char s[] = {5};
	char t[] = {0};

	printf("%i\n", memcmp(s, t, 0));
}*/
