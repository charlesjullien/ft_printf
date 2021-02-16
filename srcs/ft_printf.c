/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:17:07 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/16 14:38:15 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_type(t_param *param)
{
	char c;

	c = param->type;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
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
		print_x(param, va_arg(param->ap, unsigned int));
	if (param->type == 'p')
		print_p(param);
	if (param->type == '%')
		print_pct(param);
}

int		find_specifiers(t_param *param, const char *str, int *j)
{
	if (str[*j + 1])
		*j = *j + 1;
	parse_flags(param, &str[*j]);
	while (str[*j] == '0' || str[*j] == '-')
		*j = *j + 1;
	if (str[*j] == '*')
	{
		param->width = va_arg(param->ap, int);
		if (param->width < 0)
			param->padding = ' ';
		if (param->width < 0)
			param->width = param->width * (-1);
		*j = *j + 1;
	}
	else if (ft_isdigit(str[*j]))
		param->width = ft_atoi(&str[*j]);
	while (ft_isdigit(str[*j]))
		*j = *j + 1;
	if (str[*j] == '.')
		parse_precision(param, &str[*j]);
	while (str[*j] == '.' || str[*j] == '*' || ft_isdigit(str[*j]) ||
			str[*j] == '-')
		*j = *j + 1;
	param->type = str[*j];
	return (check_type(param));
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
	ft_strlcpy(param->null, "(null)", 7);
	param->ret = 0;
	param->width = 0;
	param->precision = -1;
	return (param);
}

int		ft_printf(const char *str, ...)
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
		if (str[i] == '%')
		{
			if (find_specifiers(param, str, &i) == 0)
				return (-1);
			find_type(param);
			reinit_param(param);
		}
		else
			param->ret += ft_putchar(str[i]);
		i++;
	}
	va_end(param->ap);
	i = param->ret;
	free(param);
	return (i);
}
