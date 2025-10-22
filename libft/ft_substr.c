/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:04:07 by becanals          #+#    #+#             */
/*   Updated: 2025/09/30 17:11:30 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strl;

	if (start > ft_strlen(s))
		return (ft_strndup((char *)&s[ft_strlen(s)], 1));
	strl = ft_strlen(&s[start]);
	if (strl > len)
		strl = len;
	return (ft_strndup((char *)&s[start], strl));
}
