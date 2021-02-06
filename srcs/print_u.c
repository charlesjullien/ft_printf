/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:44:16 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/04 21:06:40 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_precision2(t_param *param, int n, int len)
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
		while(param->width > len)
		{
			param->ret += ft_putchar('0');
			param->width--;
		}
		ft_putnbr_fd(n, 1);
	}
}

void	print_rest2(t_param *param, int n, int len, int displayed_prec)
{
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_putnbr_fd(n, 1);	
}

void	print_greater_width2(t_param *param, int n, int len, int displayed_prec)
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
		print_rest2(param, n, len, displayed_prec);
	}
}

void	print_precision2(t_param *param, int n, int len, int displayed_prec)
{
	if (param->precision >= param->width) //attention à width si on l'a déjà -- dans get_disp_prec.
	{
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_putnbr_fd(n, 1);
	}
	else
		print_greater_width2(param, n, len, displayed_prec);
}

void	print_u(t_param *param)
{
	int		n;
	int 	len;
	int 	displayed_prec;

	n = va_arg(param->ap, unsigned);
	len = get_int_len(param, n);
	if (n == 0 && param->precision == 0 && param->width == 0)
		return ;
	if (param->precision >= 0)
		displayed_prec = param->precision - len;
	if (param->precision < 0)
		print_no_precision2(param, n, len);
	while (param->precision < 0 && !param->padding && param->width > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if (param->width == len)
			ft_putnbr_fd(n, 1);
	}
	if (param->precision >= 0)
		print_precision2(param, n, len, displayed_prec);
}
