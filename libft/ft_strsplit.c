/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:02:56 by adandres          #+#    #+#             */
/*   Updated: 2018/04/19 19:27:03 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		cl(char const *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static int		cs(char const *str, char c)
{
	int	i;
	int	count;
	int	buff;

	i = 0;
	count = 0;
	buff = 1;
	while (str[i])
	{
		if (str[i] != c && buff)
		{
			count++;
			i++;
			buff = 0;
		}
		if (!buff && (str[i - 1] == c) && (str[i] != c))
			count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		x;
	int		y;
	char	**tab;

	i = 0;
	x = 0;
	if (s == NULL || (tab = (char **)malloc(sizeof(s) * (cs(s, c) + 1))) == 0)
		return (NULL);
	while (s[i])
	{
		y = 0;
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if ((tab[x] = (char*)malloc(sizeof(char) * (cl(s, i, c)))) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				tab[x][y++] = s[i++];
			tab[x++][y] = '\0';
		}
	}
	tab[x] = NULL;
	return (tab);
}
