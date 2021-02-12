/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:28:32 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/12 19:06:19 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_len(t_param *param, char *s)
{
	if (param->precision < 0)
		return (ft_strlen(s));
	if (param->precision >= ft_strlen(s))
		return (ft_strlen(s));
	if (param->precision < ft_strlen(s) && param->precision >= 0)
		return (param->precision);
	return (param->precision);
}

void	print_padding_zero(t_param *param, char *s, int len)
{
	int i;

	i = 0;
	while (param->padding == '0' && param->width > 0)
	{
		param->ret += ft_putchar('0');
		param->width--;
	}
	while (param->padding == '0' && len > 0)
	{
		param->ret += ft_putchar(s[i]);
		len--;
		i++;
	}
}

void	print_padding_minus(t_param *param, char *s, int len)
{
	int	i;

	i = 0;
	while (param->padding == ' ' && len > 0)
	{
		param->ret += ft_putchar(s[i]);
		len--;
		i++;
	}
	while (param->padding == ' ' && param->width > 0)
	{
		param->ret += ft_putchar(' ');
		param->width--;
	}
}

void	print_s(t_param *param)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = va_arg(param->ap, char*);
	if (!s)
		s = param->null;
	len = get_len(param, s);
	param->width = param->width - len;
	while (!param->padding && param->width > 0)
	{
		param->ret += ft_putchar(' ');
		param->width--;
	}
	if (param->padding == ' ')
		print_padding_minus(param, s, len);
	if (param->padding == '0')
		print_padding_zero(param, s, len);
	while (!param->padding && len > 0)
	{
		param->ret += ft_putchar(s[i]);
		i++;
		len--;
	}
}
