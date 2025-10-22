/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:33:48 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 19:02:44 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*rtrn;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < n)
		n = ft_strlen(s);
	rtrn = ft_calloc(n + 1, 1);
	if (!rtrn)
		return (NULL);
	ft_memcpy(rtrn, s, n);
	return (rtrn);
}
