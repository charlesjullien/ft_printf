/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:32:54 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/10 21:36:43 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_no_precision3(t_param *param, unsigned int n, int len)
{
	if (param->padding == ' ')
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
		while (param->width > len)
		{
			param->ret += ft_putchar('0');
			param->width--;
		}
		ft_put_hexa(param, n);
	}
}

void	print_rest3(t_param *param, unsigned int n, int displayed_prec)
{
	while (displayed_prec > 0)
	{
		param->ret += ft_putchar('0');
		displayed_prec--;
	}
	ft_put_hexa(param, n);
}

void	big_width(t_param *param, unsigned int n, int len, int disp_prec)
{
	if (param->padding == ' ')
	{
		while (disp_prec > 0)
		{
			param->ret += ft_putchar('0');
			disp_prec--;
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
		print_rest3(param, n, disp_prec);
	}
}

void	print_prec3(t_param *param, unsigned int n, int len, int disp_prec)
{
	if (param->precision == 0 && n == 0)
	{
		while (param->width  > 0)
		{
			param->ret += ft_putchar(' ');
			param->width--;
		}
		return ;
	}
	if (param->precision >= param->width)
	{
		while (disp_prec > 0)
		{
			param->ret += ft_putchar('0');
			disp_prec--;
		}
		ft_put_hexa(param, n);
	}
	else
		big_width(param, n, len, disp_prec);
}

void	print_x(t_param *param, unsigned long int n)
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
	if (param->precision < 0 && param->width <= len && !param->padding)
		ft_put_hexa(param, n);
	while (param->precision < 0 && !param->padding && param->width > len)
	{
		param->ret += ft_putchar(' ');
		param->width--;
		if (param->width == len)
			ft_put_hexa(param, n);
	}
	if (param->precision >= 0)
		print_prec3(param, n, len, displayed_prec);
}
