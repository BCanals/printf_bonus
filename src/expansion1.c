/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:02:27 by becanals          #+#    #+#             */
/*   Updated: 2025/10/29 18:26:49 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_app_zeros(t_parser *parser)
{
	char	*str;
	size_t	num_len;
	size_t	zero_len;

	if (parser->flag_zer_min == 1)
		num_len = parser->flag_len;
	if (parser->precision)
		num_len = parser->prec_len;
	if (ft_strlen(parser->wop) < num_len)
	{
		str = ft_calloc(num_len + 1, 1);
		if (!str)
			return (ft_clean_up(parser), 0);
		ft_memset(str, '0', num_len);
		zero_len = num_len - ft_strlen(parser->wop) - 1;
		ft_memcpy(&(str[zero_len]), parser->wop, ft_strlen(parser->wop));
		free(parser->wop);
		parser->wop = str;
	}
	return (1);
}

static int	ft_app_hash(t_parser *parser)
{
	int		dif;
	char	*str;

	dif = ft_strlen(parser->wop) - parser->prec_len;
	if (dif < 1)
	{
		if (dif == 1)
			str = ft_calloc(ft_strlen(parser->wop) + 2, 1);
		else
			str = ft_calloc(ft_strlen(parser->wop) + 3, 1);
		if (!str)
			return (ft_clean_up(parser), 0);
		if (dif == 1)
			ft_memcpy(&str[1], parser->wop, ft_strlen(parser->wop));
		else
			ft_memcpy(&str[2], parser->wop, ft_strlen(parser->wop));
		free(parser->wop);
		parser->wop = str;
	}
	(parser->wop)[0] = '0';
	(parser->wop)[1] = 'x';
	return (1);
}

static int	ft_app_spc_pls(t_parser *parser)
{
	char	*str;

	if (ft_strlen(parser->wop) == parser->prec_len)
	{
		str = ft_calloc(ft_strlen(parser->wop) + 2, 1);
		if (!str)
			return (ft_clean_up(parser), 0);
		ft_memcpy(&(str[1]), parser->wop, ft_strlen(parser->wop));
		free(parser->wop);
		parser->wop = str;
	}
	if (parser->flag_spc_pls == 1)
		(parser->wop)[0] = ' ';
	else
		(parser->wop)[0] = '+';
	return (1);
}

static int	ft_shorten_str(t_parser *parser)
{
	char *str;

	if (parser->prec_len < ft_strlen(parser->wop))
	{
		str = ft_strdup_n(parser->wop, parser->prec_len);
		if (!str)
			return (ft_clean_up(parser), 0);
		free(parser->wop);
		parser->wop = str;
	}
	return (1);
}

int	ft_expansion(t_parser *parser)
{
	if (ft_memchr("diuxX", parser->flag_converter, 5))
	{
		if (!ft_app_zeros(parser))
			return (ft_clean_up(parser), 0);
		if (ft_memchr("xX", parser->flag_converter, 2) && parser->flag_hash)
			if (!ft_app_hash(parser))
				return (ft_clean_up(parser), 0);
		if (ft_memchr("di", parser->flag_converter, 2) && parser->flag_spc_pls)
			if (!ft_app_spc_pls(parser))
				return (ft_clean_up(parser), 0);
	}
	else if (parser->flag_converter == 's' && parser->precision)
		if (!ft_shorten_str(parser))
			return (ft_clean_up(parser), 0);
	if (ft_memchr("cspdiuxX", parser->flag_converter, 8) && parser->flag_len)
		if (!ft_expand_buff(parser))
			return (ft_clean_up(parser), 0);
	return (1);
}
