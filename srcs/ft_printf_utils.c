/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:54:33 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 17:07:51 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int_len(t_param *param, int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while (n > 10 || n < -10)
	{
		len++;
		n = n / 10;
	}
	param->ret = param->ret + len;
	return (len);
}

int	parse(t_param *param, int n, int *ptr_len)
{
	int displayed_prec;

	displayed_prec = param->precision - *ptr_len;
	if (n < 0 && displayed_prec >= 0)
	{
		displayed_prec++;
		param->width--;
	}
	return (displayed_prec);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	reinit_param(t_param *param)
{
	param->padding = '\0';
	param->type = '\0';
	param->width = 0;
	param->precision = -1;
	ft_strlcpy(param->base, "0123456789abcdef", 17);
}
