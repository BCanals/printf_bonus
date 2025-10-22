/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:35:31 by becanals          #+#    #+#             */
/*   Updated: 2025/09/30 16:32:33 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	ret = ft_calloc(ft_strlen(s) + 1, 1);
	if (!ret)
		return (NULL);
	i = 0;
	i--;
	while (s[++i])
		ret[i] = f(i, s[i]);
	return (ret);
}
