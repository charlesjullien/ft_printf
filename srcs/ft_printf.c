/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:17:07 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 17:00:45 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_if_valid_spec(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (ft_strchr("cspdiuxX", str[i]))
		return (1);
	return (0);
}

void	find_type(t_param *param)
{
	if (param->type == 'c')
		print_c(param);
	if (param->type == 's')
		print_s(param);
	if (param->type == 'd' || param->type == 'i')
		print_d_or_i(param);
	if (param->type == 'u')
		print_u(param);
	if (param->type == 'x' || param->type == 'X')
		print_x(param, va_arg(param->ap, unsigned long));
	if (param->type == 'p')
		print_p(param);
}

void	find_specifiers(t_param *param, const char *str, int *j)
{
	*j = *j + 1;
	if (str[*j] == '0')
		param->padding = '0';
	else if (str[*j] == '-')
		param->padding = ' ';
	if (param->padding)
		*j = *j + 1;
	if (str[*j] == '*')
	{
		param->width = va_arg(param->ap, int);
		*j = *j + 1;
	}
	else
		param->width = ft_atoi(&str[*j]);
	while (ft_isdigit(str[*j]))
		*j = *j + 1;
	if (str[*j] == '.')
		parse_precision(param, str, &j);
	param->type = str[*j];
}

t_param	*init_param(void)
{
	t_param	*param;

	param = (t_param*)malloc(sizeof(t_param));
	if (param == NULL)
		return (NULL);
	param->padding = '\0';
	param->type = '\0';
	ft_strlcpy(param->base, "0123456789abcdef", 17);
	param->ret = 0;
	param->width = 0;
	param->precision = -1;
	return (param);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_param	*param;

	i = 0;
	param = init_param();
	if (param == NULL)
		return (-1);
	va_start(param->ap, str);
	while (str[i])
	{
		if (str[i] == '%' && check_if_valid_spec(&str[i + 1]))
		{
			find_specifiers(param, str, &i);
			find_type(param);
			reinit_param(param);
		}
		else
		{
			ft_putchar(str[i]);
			param->ret++;
		}
		i++;
	}
	va_end(param->ap);
	return (param->ret);
}
