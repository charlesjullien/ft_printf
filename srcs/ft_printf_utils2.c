/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:35:47 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 19:02:18 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(t_param *param, const char *str, int *j)
{
	if (str[*j] == '*')
	{
		param->precision = va_arg(param->ap, int);
		*j = *j + 1;
	}
	else
		param->precision = ft_atoi(&str[*j]);
	while (ft_isdigit(str[*j]))
		*j = *j + 1;
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

void	ft_put_hexa(t_param *param, unsigned long n)
{
	if (n >= 16)
		ft_put_hexa(param, n / 16);
	param->ret += ft_putchar(param->base[n % 16]);
}
