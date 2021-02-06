/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:39:26 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/02 17:31:51 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0)
	{
		return (srclen);
	}
	while (i + destlen < size - 1 && src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[destlen + i] = '\0';
	}
	if (size < destlen)
	{
		return (srclen + size);
	}
	return (destlen + srclen);
}
