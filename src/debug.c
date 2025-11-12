/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:32:10 by becanals          #+#    #+#             */
/*   Updated: 2025/11/12 16:32:13 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	debuger(t_parser *parser)
{
	ft_putstr_fd("====>>> now at: ", 1);
	ft_putchar_fd(parser->format[0], 1);
	ft_putchar_fd(10, 1);
	(parser->stt_fts_array)[parser->state](parser);
}

void	ft_const_printer(t_parser *parser)
{
	char	*str;

	ft_putstr_fd("flag conv: ", 1);
	ft_putchar_fd(parser->flag_converter, 1);
	ft_putstr_fd("\nflag hash: ", 1);
	ft_putchar_fd(parser->flag_hash + '0', 1);
	ft_putstr_fd("\nflag sign: ", 1);
	ft_putchar_fd(parser->flag_sign + '0', 1);
	ft_putstr_fd("\nflag zer_min: ", 1);
	ft_putchar_fd(parser->flag_zer_min + '0', 1);
	ft_putstr_fd("\nflag len: ", 1);
	str = ft_itoa(parser->flag_len);
	ft_putstr_fd(str, 1);
	free(str);
	ft_putstr_fd("\nprecision: ", 1);
	ft_putchar_fd(parser->precision + '0', 1);
	ft_putstr_fd("\nprec len: ", 1);
	str = ft_itoa(parser->prec_len);
	ft_putstr_fd(str, 1);
	free(str);
}

