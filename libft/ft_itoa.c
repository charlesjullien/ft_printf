/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:06:04 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/02 18:04:35 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(long int num)
{
	int		len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int		get_sign(long int num)
{
	int		sign;

	if (num < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	n_copy;
	int			len;

	n_copy = n;
	len = get_len(n_copy);
	if (n_copy < 0)
		n_copy = n_copy * (-1);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= get_sign(n))
	{
		str[len] = n_copy % 10 + 48;
		n_copy = n_copy / 10;
		len--;
	}
	if (get_sign(n) == 1)
		str[len] = '-';
	return (str);
}
