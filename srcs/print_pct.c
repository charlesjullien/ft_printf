/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:54:54 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/09 14:09:10 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_pct(t_param *param)
{
	char c;

	c = ' ';
	if (param->padding == '0')
		c = '0';
	while (param->width > 1 && param->padding != ' ')
	{
		param->ret += ft_putchar(c);
		param->width--;
	}
	param->ret += ft_putchar('%');
	while (param->width > 1)
	{
		param->ret += ft_putchar(c);
		param->width--;
	}
}
