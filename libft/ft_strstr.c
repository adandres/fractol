/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:27:29 by adandres          #+#    #+#             */
/*   Updated: 2018/04/16 11:42:00 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int long_to;
	int e;
	int a;

	long_to = 0;
	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (to_find[long_to])
		long_to++;
	while (str[i])
	{
		e = 0;
		a = i;
		while (str[a] == to_find[e])
		{
			if (e == long_to - 1)
				return ((char *)str + a - e);
			e++;
			a++;
		}
		i++;
	}
	return (0);
}
