/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:44:03 by becanals          #+#    #+#             */
/*   Updated: 2025/09/23 18:13:26 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	rtrn;

	if (!str)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	rtrn = 0;
	while (*str >= 48 && *str <= 57)
	{
		rtrn = rtrn * 10 + (*str - 48);
		str++;
	}
	rtrn *= sign;
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
