/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:44:16 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/12 19:29:22 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	no_prec_u(t_param *param, unsigned int n, int len)
{
	if (param->padding == ' ')
	{
		ft_putnbr_fd(n, 1);
		while (param->width > len)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
	}
	else if (param->padding == '0')
	{
		while (param->width > len)
		{
			param->ret += ft_putchar('0');
			param->width--;
		}
		ft_putnbr_fd(n, 1);
	}
}

void	print_rest_u(t_param *param, unsigned int n, int displayed_prec)
{
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_putnbr_fd(n, 1);
}

void	width_u(t_param *param, unsigned int n, int len, int displayed_prec)
{
	if (param->padding == ' ')
	{
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
		print_rest_u(param, n, displayed_prec);
	}
}

void	prec_u(t_param *param, unsigned int n, int len, int displayed_prec)
{
	if (param->precision == 0 && n == 0)
	{
		while (param->width > 0)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
		return ;
	}
	if (param->precision >= param->width)
	{
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_putnbr_fd(n, 1);
	}
	else
		width_u(param, n, len, displayed_prec);
}

void	print_u(t_param *param)
{
	unsigned int	n;
	int				len;
	int				displayed_prec;

	n = va_arg(param->ap, unsigned int);
	len = get_int_len(param, n);
	if (n == 0 && param->precision == 0 && param->width == 0)
		return ;
	if (param->precision >= 0)
		displayed_prec = param->precision - len;
	if (param->precision < 0)
		no_prec_u(param, n, len);
	if (len >= param->width && param->precision < 0 && !param->padding)
		ft_putnbr_fd(n, 1);
	while (param->precision < 0 && !param->padding && param->width > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if (param->width == len)
			ft_putnbr_fd(n, 1);
	}
	if (param->precision >= 0)
		prec_u(param, n, len, displayed_prec);
}
