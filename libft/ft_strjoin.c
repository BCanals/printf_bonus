/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:15:58 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 18:24:39 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*rtrn;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	rtrn = ft_calloc(ls1 + ls2 + 1, 1);
	if (!rtrn)
		return (NULL);
	ft_memcpy(rtrn, s1, ls1);
	ft_memcpy(&rtrn[ls1], s2, ls2);
	return (rtrn);
}
