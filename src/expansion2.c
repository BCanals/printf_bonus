/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:50:21 by becanals          #+#    #+#             */
/*   Updated: 2025/11/02 21:13:07 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static size_t	my_ft_strlen(t_parser *parser)
{
	if (parser->flag_converter == 'c')
		return (1);
	return (ft_strlen(parser->wop));
}

int	ft_expand_buff(t_parser *parser)
{
	size_t	buf;
	char	*str;


	//ft_putstr_fd("in shroten_str. pointer = ", 1);
	//ft_putstr_fd(ft_utoa_base((size_t) parser->wop, "0123456789abcdef"), 1);
	//ft_putchar_fd('\n', 1);
	if (my_ft_strlen(parser) < parser->flag_len)
	{
		str = ft_calloc(parser->flag_len + 1, 1);
		if (!str)
			return (parser->kill = 1, 0);
		ft_memset(str, ' ', parser->flag_len);
		if (parser->flag_zer_min == 2)
			ft_memcpy(str, parser->wop, my_ft_strlen(parser));
		else
		{
			buf = parser->flag_len - my_ft_strlen(parser);
			ft_memcpy(&(str[buf]), parser->wop, my_ft_strlen(parser));
		}
		free(parser->wop);
		parser->wop = str;
	}
	return (1);
}
