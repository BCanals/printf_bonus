/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:44:03 by becanals          #+#    #+#             */
/*   Updated: 2025/10/30 19:37:03 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_atou(const char *str)
{
	size_t	rtrn;

	if (!str)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	rtrn = 0;
	while (*str >= 48 && *str <= 57)
	{
		rtrn = rtrn * 10 + (*str - 48);
		str++;
	}
	return (rtrn);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	argc++;
	printf("%i\n%i\n", ft_atoi(argv[1]), atoi(argv[1]));
}*/
