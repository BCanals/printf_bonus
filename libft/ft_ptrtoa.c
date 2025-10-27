/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:09:06 by becanals          #+#    #+#             */
/*   Updated: 2025/10/27 18:00:02 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(size_t n)
{
	if (n <= 16)
		return (1);
	return (ft_get_size(n / 16) + 1);
}

static void	ft_fill_ptrtoa(char **s, size_t n, char *base)
{
	if (n >= 16)
		ft_fill_ptrtoa(s, n / 16, base);
	*s[0] = base[n % 16];
	(*s)++;
	return ;
}

char	*ft_ptrtoa(size_t n)
{
	char	*buff;
	char	*ret;

	buff = ft_calloc(ft_get_size(n) + 3, 1);
	if (!buff)
		return (NULL);
	ret = buff;
	ret[0] = '0';
	ret[1] = 'x';
	buff += 2;
	ft_fill_ptrtoa(&buff, n, "0123456789abcdef");
	return (ret);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{
	argc++;
	printf("%s\n", ft_itoa(atoi(argv[1])));
}*/
