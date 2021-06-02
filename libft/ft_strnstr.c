/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:30:44 by adandres          #+#    #+#             */
/*   Updated: 2018/04/18 13:59:48 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t find;
	size_t e;
	size_t a;

	i = 0;
	find = 0;
	while (to_find[find++])
		;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		e = 0;
		a = i;
		while (str[a++] == to_find[e++] && e <= find && a <= len)
		{
			if (e == find - 1)
				return ((char *)str + a - e);
		}
		i++;
	}
	return (0);
}
