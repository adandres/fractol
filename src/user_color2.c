/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_color2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:36:18 by adandres          #+#    #+#             */
/*   Updated: 2018/12/23 11:21:24 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

void		test7(t_fat *fat, int j, int i, int a)
{
	if (j == 250)
		fat->mlx.img.data[i * W + 49 + a] = rgb(0, 0, a * 255 / 300);
	else if (j == 300)
		fat->mlx.img.data[i * W + 49 + a] = rgb(0, a * 255 / 300, 0);
	else if (j == 350)
		fat->mlx.img.data[i * W + 49 + a] = rgb(a * 255 / 300, 0, 0);
}

void		test3(t_fat *fact, int i)
{
	t_fat	fat;
	int		j;
	int		a;

	fat = *fact;
	j = i;
	while (i <= j + 7)
	{
		a = 0;
		while (49 + a <= 350)
		{
			if (49 + a == 49 + (j + 3) - i || 49 + a == 350 + (i - (j + 3)))
				fat.mlx.img.data[i * W + 49 + a] = 0xffffff;
			else if (49 + a == 49 + (i - (j + 4)) || 49 + a == 350 + j + 4 - i)
				fat.mlx.img.data[i * W + 49 + a] = 0xffffff;
			else if ((i == j || i == j + 7) && 49 + a < 250 + 97 && 49 + a > 52)
				fat.mlx.img.data[i * W + 49 + a] = 0xffffff;
			else if (i > j && i < j + 7 && 49 + a > 49 + (j + 3) - i &&
					49 + a < 350 + (i - (j + 3)) && 49 + a > 49 + (i - (j + 4))
					&& 49 + a < 350 + (j + 4) - i)
				test7(&fat, j, i, a);
			a++;
		}
		i++;
	}
}
