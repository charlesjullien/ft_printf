/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:07:05 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 16:13:59 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_precision4(t_param *param, int n, int len)
{
	if (param->padding == ' ' || !param->padding)
	{
		param->ret += ft_putstr("0x");
		ft_put_hexa(param, n);
		while (param->width > len)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
	}
	else if (param->padding == '0')
	{
		param->ret += ft_putstr("0x");
		while(param->width > len)
		{
			param->ret += ft_putchar('0');
			param->width--;
		}
		ft_put_hexa(param, n);
	}
}

void	print_rest4(t_param *param, int n, int len, int displayed_prec)
{
	param->ret += ft_putstr("0x");
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_put_hexa(param, n);
}

void	print_greater_width4(t_param *param, int n, int len, int displayed_prec)
{
	if (param->padding == ' ')
	{
		param->ret += ft_putstr("0x");
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
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
		print_rest4(param, n, len, displayed_prec);
	}
}

void	print_precision4(t_param *param, int n, int len, int displayed_prec)
{
	if (param->precision >= param->width) //attention à width si on l'a déjà -- dans get_disp_prec.
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
		print_greater_width4(param, n, len, displayed_prec);
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
		print_no_precision4(param, n, len);
	while (param->precision < 0 && !param->padding && param->width > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if(param->width == len)
			param->ret += ft_putstr("0x");
		if (param->width == len)
			ft_put_hexa(param, n);
	}
	if (param->precision >= 0)
		print_precision4(param, n, len, displayed_prec);
}
