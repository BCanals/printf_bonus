/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:21 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 19:11:40 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	while (++i < n && str1[i] && str1[i] == str2[i])
		;
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main (void)
{
	printf("syst: %i\nmine: %i\n", strncmp("1234", "1235", 4), ft_strncmp("1234",
			 "1235", 4)); 
}*/
