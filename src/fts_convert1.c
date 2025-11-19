/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_convert1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:27:40 by becanals          #+#    #+#             */
/*   Updated: 2025/11/18 20:58:16 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_convert_c(t_parser *parser)
{
	char	*c;

	c = ft_calloc(2, 1);
	if (!c)
		return (parser->kill = 1, (void)0);
	c[0] = va_arg(*(parser->args), int);
	parser->wop = c;
	if (c[0] == 0)
		(parser->add_return)++;
}

void	ft_convert_s(t_parser *parser)
{
	char	*str;
	char	*rtrn;

	str = va_arg(*(parser->args), char *);
	if (!str)
		rtrn = ft_strdup("(null)");
	else
		rtrn = ft_strdup(str);
	if (!rtrn)
		return (parser->kill = 1, (void)0);
	parser->wop = rtrn;
}

void	ft_convert_p(t_parser *parser)
{
	void	*ptr;
	char	*rtrn;

	ptr = va_arg(*(parser->args), void *);
	if (!ptr)
		rtrn = ft_strdup("(nil)");
	else
		rtrn = ft_ptrtoa((size_t) ptr);
	if (!rtrn)
		return (parser->kill = 1, (void)0);
	parser->wop = rtrn;
}

void	ft_convert_di(t_parser *parser)
{
	char	*str;
	int		num;

	num = va_arg(*(parser->args), int);
	str = ft_itoa(num);
	if (!str)
		return (parser->kill = 1, (void)0);
	parser->wop = str;
}
