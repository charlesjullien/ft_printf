/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:18:03 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/06 16:32:38 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_parameters		t_param;
struct							s_parameters
{
		va_list ap;
		char	padding;
		char	type;
		char	base[17];
		int			ret;
		int			width;
		int			precision;
		char		base[17];
};

int		ft_printf(const char *str, ...);
void	ft_put_hexa(t_param *param, unsigned long n);
void	set_base_maj(t_param *param);
void	get_hexa_len(unsigned long int n, int *hexa_len);
void	parse_precision(t_param *param, const char *str, int *j);
void	reinit_param(t_param *param);
int		ft_putstr(char *str); //existe aussi ds libft?
int		ft_putchar(char c); //existe aussi dans libf ?
int		parse(t_param *param, int n, int *ptr_len);
int		get_int_len(t_param *param, int n);
void	print_d_or_i(t_param *param);
void	print_c(t_param *param);
void	print_s(t_param *param);
void	print_u(t_param *param);
void	print_p(t_param *param);
void	print_x_or_X(t_param *param, unsigned long int n);

#endif
