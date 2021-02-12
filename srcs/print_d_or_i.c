/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_or_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:11:32 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/12 19:33:51 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	no_prec_d_i(t_param *param, long int n, int len)
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
		if (n < 0)
		{
			ft_putchar('-');
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

void	print_rest_d_i(t_param *param, long int n, int displayed_prec)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_putnbr_fd(n, 1);
}

void	width_d_i(t_param *param, long int n, int len, int displayed_prec)
{
	if (param->padding == ' ')
	{
		if (n < 0)
		{
			ft_putchar('-');
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
		print_rest_d_i(param, n, displayed_prec);
	}
}

void	prec_d_i(t_param *param, long int n, int len, int displayed_prec)
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
		if (n < 0)
		{
			ft_putchar('-');
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
		width_d_i(param, n, len, displayed_prec);
}

void	print_d_or_i(t_param *param)
{
	long int	n;
	int			len;
	int			displayed_prec;

	n = va_arg(param->ap, int);
	len = get_int_len(param, n);
	if (n == 0 && param->precision == 0 && !param->width)
		return ;
	if (param->precision >= 0)
		displayed_prec = parse(param, n, &len);
	if (param->precision < 0)
		no_prec_d_i(param, n, len);
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
		prec_d_i(param, n, len, displayed_prec);
}
