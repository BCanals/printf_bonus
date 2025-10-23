/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:54:16 by bizcru            #+#    #+#             */
/*   Updated: 2025/10/23 19:15:38 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putnbr_hex(size_t num, char type)
{
	char	*num;
	char	*base;
	char	*rtrn;

	if (type == 'x' )
		base = ft_strdup("0123456789abcdef");
	else if (type == 'X')
		base = ft_strdup("0123456789ABCDEF");
	if (!base)
		return (NULL);
	num = ft_putnbr_base_u(i, base);
	free(base);
	if (!num)
		return (NULL);
	rtrn = ft_calloc(sizeof(num) + 2, 1);
	if (!rtrn)
		return (free(num), NULL);
	rtrn[0] = '0';
	rtrn[1] = 'x';
	ft_memmove(rtrn[2], num, ft_strlen(num));
	free(num);
	return (rtrn);
}
