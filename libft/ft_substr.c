/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:47:22 by cjullien          #+#    #+#             */
/*   Updated: 2020/12/07 17:20:20 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < len)
		len = (unsigned int)ft_strlen(s);
	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start > (unsigned int)ft_strlen((char*)s))
	{
		new[i] = '\0';
		return (new);
	}
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
