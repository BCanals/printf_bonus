/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:09:06 by becanals          #+#    #+#             */
/*   Updated: 2025/10/26 20:41:59 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(unsigned int n, size_t base_len)
{
	if (n <= base_len)
		return (1);
	return (ft_get_size(n / base_len, base_len) + 1);
}

static void	ft_fill_utoa(char **s, unsigned int n, char *base, size_t base_len)
{
	if (n >= base_len)
		ft_fill_utoa(s, n / base_len, base, base_len);
	*s[0] = base[n % base_len];
	(*s)++;
	return ;
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char	*buff;
	char	*ret;
	size_t	base_len;

	base_len = ft_strlen(base);
	buff = ft_calloc(ft_get_size(n, base_len) + 1, 1);
	if (!buff)
		return (NULL);
	ret = buff;
	ft_fill_utoa(&buff, n, base, base_len);
	return (ret);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{
	argc++;
	printf("%s\n", ft_itoa(atoi(argv[1])));
}*/
