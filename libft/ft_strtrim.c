/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:25:01 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 19:10:57 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtrn;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr((char *)set, s1[start]))
		start++;
	if (start == end)
		return (ft_calloc(1, 1));
	while (ft_strchr((char *)set, s1[--end]))
		;
	rtrn = ft_calloc(end - start + 2, 1);
	ft_memcpy(rtrn, &s1[start], end - start + 1);
	return (rtrn);
}
