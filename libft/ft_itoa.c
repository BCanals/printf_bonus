/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:09:06 by becanals          #+#    #+#             */
/*   Updated: 2025/09/30 17:28:51 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
			n--;
		else
			n = -n;
		i = 1;
	}
	i++;
	if (n <= 9)
		return (i);
	return (ft_get_size(n / 10) + i);
}

static void	ft_fill_itoa(char **s, int n, int first)
{
	if (first && n < 0)
	{
		(*s)[0] = '-';
		(*s)++;
	}
	if (n > 9 || n < -9)
		ft_fill_itoa(s, n / 10, 0);
	*s[0] = '0';
	if (n > 0)
		*s[0] += n % 10;
	else
		*s[0] -= n % 10;
	(*s)++;
	return ;
}

char	*ft_itoa(int n)
{
	char	*buff;
	char	*ret;

	buff = ft_calloc(ft_get_size(n) + 1, 1);
	if (!buff)
		return (NULL);
	ret = buff;
	ft_fill_itoa(&buff, n, 1);
	return (ret);
}
/*
#include <stdio.h>

int main (int argc, char **argv)
{
	argc++;
	printf("%s\n", ft_itoa(atoi(argv[1])));
}*/
