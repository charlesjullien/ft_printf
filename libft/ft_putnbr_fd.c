/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:46:30 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/07 19:08:05 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	char		c;

	num = n;
	if (num < 0)
	{
		num = num * (-1);
		write(fd, "-", 1);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	c = (num % 10) + 48;
	write(fd, &c, 1);
}
