/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:50:21 by becanals          #+#    #+#             */
/*   Updated: 2025/10/30 16:28:57 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_expand_buff(t_parser *parser)
{
	size_t	buf;
	char	*str;

	if (ft_strlen(parser->wop) < parser->flag_len)
	{
		str = ft_calloc(parser->flag_len + 1, 1);
		if (!str)
			return (ft_clean_up(parser), 0);
		ft_memset(str, ' ', parser->flag_len);
		if (parser->flag_zer_min == 2)
			ft_memcpy(str, parser->wop, ft_strlen(parser->wop));
		else
		{
			buf = parser->flag_len - ft_strlen(parser->wop);
			ft_memcpy(&(str[buf]), parser->wop, ft_strlen(parser->wop));
		}
		free(parser->wop);
		parser->wop = str;
	}
	return (1);
}
