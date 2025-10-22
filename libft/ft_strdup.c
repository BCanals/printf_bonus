/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:33:48 by becanals          #+#    #+#             */
/*   Updated: 2025/09/23 14:43:20 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*rtrn;

	if (!s)
		return (NULL);
	rtrn = ft_calloc(ft_strlen(s) + 1, 1);
	if (!rtrn)
		return (NULL);
	ft_memcpy(rtrn, s, ft_strlen(s));
	return (rtrn);
}
