/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_or_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:32:54 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 15:19:50 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_precision3(t_param *param, unsigned long int n, int len)
{
	if (param->padding == ' ' || !param->padding)
	{
		ft_put_hexa(param, n);
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
		ft_put_hexa(param, n);
	}
}

void	print_rest3(t_param *param, unsigned long int n, int len, int displayed_prec)
{
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_put_hexa(param, n);
}

void	print_greater_width3(t_param *param, unsigned long int n, int len, int displayed_prec)
{
	if (param->padding == ' ')
	{
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_put_hexa(param, n);
	}
	while (param->width - param->precision > 0 && len < param->width)
	{
		param->ret += ft_putchar(' ');
		param->width--;
	}
	if (param->padding == '0' || !param->padding)
	{
		print_rest3(param, n, len, displayed_prec);
	}
}

void	print_precision3(t_param *param, unsigned long int n, int len, int displayed_prec)
{
	if (param->precision >= param->width) //attention à width si on l'a déjà -- dans get_disp_prec.
	{
		while (displayed_prec > 0)
		{
			param->ret += ft_putchar('0');
			displayed_prec--;
		}
		ft_put_hexa(param, n);
	}
	else
		print_greater_width3(param, n, len, displayed_prec);
}

void	print_x_or_X(t_param *param, unsigned long int n)
{
	int hexa_len;
	int len;
	int	displayed_prec;

	hexa_len = 0;
	get_hexa_len(n, &hexa_len);
	len = hexa_len;
	if (param->type == 'X')
		set_base_maj(param);
	if (param->precision >= 0)
		displayed_prec = param->precision - len;
	if (param->precision < 0)
		print_no_precision3(param, n, len);
	while (param->precision < 0 && !param->padding && param->width > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if (param->width == len)
			ft_put_hexa(param, n);
	}
	if (param->precision >= 0)
		print_precision3(param, n, len, displayed_prec);
}
