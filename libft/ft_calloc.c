/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:08:10 by becanals          #+#    #+#             */
/*   Updated: 2025/09/26 19:10:48 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*rtrn;

	rtrn = malloc(nelem * elsize);
	if (!rtrn)
		return (NULL);
	ft_bzero(rtrn, nelem * elsize);
	return (rtrn);
}
