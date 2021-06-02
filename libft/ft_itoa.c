/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:50:06 by adandres          #+#    #+#             */
/*   Updated: 2018/04/16 14:13:39 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		is_negative(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int		len;
	int		tmpn;
	int		neg;
	char	*str;

	neg = 0;
	tmpn = n;
	len = 2;
	is_negative(&n, &neg);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (tmpn /= 10)
		len++;
	len += neg;
	if ((str = (char *)malloc(sizeof(*str) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
