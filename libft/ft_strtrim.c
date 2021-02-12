/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:29:44 by cjullien          #+#    #+#             */
/*   Updated: 2021/02/12 19:38:21 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				is_in_set(char c, char const *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int				is_it_different(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (is_in_set(s1[i], set) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				get_lenght(char const *s1, char const *set)
{
	int		b;
	int		e;
	int		dest_len;

	b = 0;
	e = ft_strlen((char*)s1) - 1;
	dest_len = 0;
	if (ft_strlen((char*)s1) == 1)
		return (1);
	while (is_in_set(s1[b], set) == 1)
		b++;
	while (is_in_set(s1[e], set) == 1)
		e--;
	while (b != e)
	{
		dest_len++;
		b++;
	}
	return (dest_len + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		dest_len;
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest_len = 0;
	if (s1 && is_it_different(s1, set) == 1)
		dest_len = get_lenght(s1, set);
	if (!(dest = (char*)malloc(sizeof(char) * dest_len + 1)))
		return (NULL);
	while (is_in_set(s1[i], set) == 1)
		i++;
	while (j < dest_len)
	{
		dest[j] = s1[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
