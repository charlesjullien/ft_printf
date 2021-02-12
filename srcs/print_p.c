/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:07:05 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/12 19:35:32 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	no_prec_p(t_param *param, unsigned long int n, int len)
{
	if (len >= param->width - 2 && !param->padding)
		param->ret += ft_putstr("0x");
	if (len >= param->width - 2 && !param->padding)
		ft_put_hexa(param, n);
	if (param->padding == ' ')
	{
		param->ret += ft_putstr("0x");
		ft_put_hexa(param, n);
		while (param->width - 2 > len)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
	}
	else if (param->padding == '0')
	{
		param->ret += ft_putstr("0x");
		while (param->width - 2 > len)
		{
			param->ret += ft_putchar('0');
			param->width--;
		}
		ft_put_hexa(param, n);
	}
}

void	print_rest_p(t_param *param, unsigned long int n, int displayed_prec)
{
	param->ret += ft_putstr("0x");
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_put_hexa(param, n);
}

void	width_p(t_param *param, unsigned long int n, int len, int disp_prec)
{
	if (param->padding == ' ')
	{
		param->ret += ft_putstr("0x");
		while (disp_prec > 0)
		{
			param->ret += ft_putchar('0');
			disp_prec--;
		}
		ft_put_hexa(param, n);
	}
	while (param->width - 2 - param->precision > 0 && len < param->width - 2)
	{
		param->ret += ft_putchar(' ');
		param->width--;
	}
	if (param->padding == '0' || !param->padding)
	{
		print_rest_p(param, n, disp_prec);
	}
}

void	prec_p(t_param *param, unsigned long int n, int len, int displayed_prec)
{
	if (param->precision == 0 && n == 0)
	{
		if (param->padding == ' ')
			param->ret += ft_putstr("0x");
		while (param->width - 2 > 0)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
		if (param->padding != ' ')
			param->ret += ft_putstr("0x");
		return ;
	}
	if (param->precision >= param->width)
	{
		param->ret += ft_putstr("0x");
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_put_hexa(param, n);
	}
	else
		width_p(param, n, len, displayed_prec);
}

void	print_p(t_param *param)
{
	unsigned long int	n;
	int					len;
	int					hexa_len;
	int					displayed_prec;

	n = (unsigned long int)va_arg(param->ap, void*);
	hexa_len = 0;
	get_hexa_len(n, &hexa_len);
	len = hexa_len;
	if (param->precision >= 0)
		displayed_prec = param->precision - len;
	if (param->precision < 0)
		no_prec_p(param, n, len);
	while (param->precision < 0 && !param->padding && param->width - 2 > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if (param->width - 2 == len)
			param->ret += ft_putstr("0x");
		if (param->width - 2 == len)
			ft_put_hexa(param, n);
	}
	if (param->precision >= 0)
		prec_p(param, n, len, displayed_prec);
}
