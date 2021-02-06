/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:08:03 by cjullien          #+#    #+#             */
/*   Updated: 2020/11/21 19:05:45 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;
	char	*dest;
	char	*src;

	if (!destination && !source)
		return (NULL);
	i = 0;
	dest = (char*)destination;
	src = (char*)source;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
