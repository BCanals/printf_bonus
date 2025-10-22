/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:50:57 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 17:59:34 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (!little || !*little)
		return ((char *)big);
	if (!len)
		return (0);
	l_len = ft_strlen(little);
	len -= l_len;
	i = -1;
	while (++i <= len && big[i])
		if (!ft_strncmp(&big[i], little, l_len))
			return ((char *)&big[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <strings.h>

int main (void)
{
	printf("%i\n", strnstr("hello", "world", 0));
}*/
