/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:17:43 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/07 15:52:18 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char*)destination;
	src = (unsigned char*)source;
	if (!destination && !source)
		return (NULL);
	if (src < dest)
	{
		while (size-- > 0)
			dest[size] = src[size];
	}
	else
		ft_memcpy(dest, src, size);
	return (destination);
}
