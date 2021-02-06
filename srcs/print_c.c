/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:51:09 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 13:57:32 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_param *param)
{
	while (!param->padding && param->width > 1)
	{
		param->ret += ft_putchar(' ');
		param->width--;
	}
	param->ret += ft_putchar(va_arg(param->ap, int));
	while (param->padding && param->width > 1)
	{
		if (param->padding == '0')
			param->ret += ft_putchar('0');
		else if (param->padding == ' ')
			param->ret += ft_putchar(' ');
		param->width--;
	}
}
