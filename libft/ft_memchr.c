/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:35:39 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/02 17:04:15 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memory_block, int searched_char, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)memory_block;
	while (i < size)
	{
		if (str[i] == (char)searched_char)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
