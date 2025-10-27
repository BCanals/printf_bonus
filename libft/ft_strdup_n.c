/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:33:48 by becanals          #+#    #+#             */
/*   Updated: 2025/10/27 16:50:38 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_n(const char *s, size_t n)
{
	char	*rtrn;

	if (!s)
		return (NULL);
	rtrn = ft_calloc(n + 1, 1);
	if (!rtrn)
		return (NULL);
	ft_memcpy(rtrn, s, n);
	return (rtrn);
}
