/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_or_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:11:32 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 18:17:34 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_precision(t_param *param, int n, int len)
{
	if (param->padding == ' ' || !param->padding)
	{
		while (param->width > len)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
		ft_putnbr_fd(n, 1);
	}
	else if (param->padding == '0')
	{
		if (n < 0)
		{
			param->ret += ft_putchar('-');
			n = n * (-1);
		}
		while (param->width > len)
		{
			param->ret += ft_putchar('0');
			param->width--;
		}
		ft_putnbr_fd(n, 1);
	}
}

void	print_rest(t_param *param, int n, int len, int displayed_prec)
{
	if (n < 0)
	{
		param->ret += ft_putchar('-');
		n = n * (-1);
	}
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_putnbr_fd(n, 1);
}

void	print_greater_width(t_param *param, int n, int len, int displayed_prec)
{
	if (param->padding == ' ')
	{
		if (n < 0)
		{
			param->ret += ft_putchar('-');
			n = n * (-1);
		}
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_putnbr_fd(n, 1);
	}
	while (param->width - param->precision > 0 && len < param->width)
	{
		param->ret += ft_putchar(' ');
		param->width--;
	}
	if (param->padding == '0' || !param->padding)
	{
		print_rest(param, n, len, displayed_prec);
	}
}

void	print_precision(t_param *param, int n, int len, int displayed_prec)
{
	if (param->precision >= param->width)
	{
		if (n < 0)
		{
			param->ret += ft_putchar('-');
			n = n * (-1);
		}
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_putnbr_fd(n, 1);
	}
	else
		print_greater_width(param, n, len, displayed_prec);
}

void	print_d_or_i(t_param *param)
{
	int		n;
	int 	len;
	int 	displayed_prec;

	n = va_arg(param->ap, int);
	len = get_int_len(param, n);
	if (n == 0 && param->precision == 0 && !param->width)
		return ;
	if (param->precision >= 0)
		displayed_prec = parse(param, n, &len);
	if (param->precision < 0)
		print_no_precision(param, n, len);
	while (param->precision < 0 && !param->padding && param->width > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if (param->width == len)
			ft_putnbr_fd(n, 1);
	}
	if (param->precision >= 0)
		print_precision(param, n, len, displayed_prec);
}
