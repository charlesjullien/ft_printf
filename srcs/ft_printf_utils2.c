/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:35:47 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/14 16:47:03 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_flags(t_param *param, const char *str)
{
	int i;

	i = 0;
	while (str[i] == '0')
	{
		param->padding = '0';
		i++;
	}
	while (str[i] == '-')
	{
		param->padding = ' ';
		i++;
	}
}

void	parse_precision(t_param *param, const char *str)
{
	int i;

	i = 1;
	if (str[i] == '*')
		param->precision = va_arg(param->ap, int);
	else
		param->precision = ft_atoi(&str[i]);
}

void	get_hexa_len(unsigned long int n, int *hexa_len)
{
	if (n >= 16)
		get_hexa_len((unsigned long int)(n / 16), hexa_len);
	*hexa_len = *hexa_len + 1;
}

void	set_base_maj(t_param *param)
{
	int i;

	i = 0;
	while (param->base[i])
	{
		if (param->base[i] >= 97 && param->base[i] <= 102)
			param->base[i] = param->base[i] - 32;
		i++;
	}
}

void	ft_put_hexa(t_param *param, unsigned long int n)
{
	if (n >= 16)
		ft_put_hexa(param, (unsigned long int)(n / 16));
	param->ret += ft_putchar(param->base[n % 16]);
}
