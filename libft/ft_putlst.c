/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:36:26 by becanals          #+#    #+#             */
/*   Updated: 2025/10/27 16:31:12 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putcont(void *s)
{
	char *str;

	str = (char *)s;
	while (*str)
		write(1, str++, 1);
}

void	ft_putlst(t_list *list)
{
	ft_lstiter(list, ft_putcont);
}
/*
int main (void)
{
	ft_putstr_fd("hello world", 1);
}*/
