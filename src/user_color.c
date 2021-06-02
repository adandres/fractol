/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 03:49:17 by adandres          #+#    #+#             */
/*   Updated: 2018/12/23 11:21:03 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

void		test(t_fat *fact)
{
	t_fat	fat;
	int		x;
	int		y;
	float	t;
	int		a;

	fat = *fact;
	y = 99;
	while (++y <= 150)
	{
		x = 49;
		while (++x <= 350)
		{
			t = 0;
			a = (x - 50) * 16 / 300;
			if (x == 50 || y == 100 || x == 350 || y == 150)
				fat.mlx.img.data[y * W + x] = 1;
			else
				fat.mlx.img.data[y * W + x] =
					linear_interpolate(fat.col[a], fat.col[a], 0, 0.99);
		}
	}
}

int			test5(t_col col, int i)
{
	if (i == 1)
		return (col.b * 300 / 255);
	if (i == 2)
		return (col.g * 300 / 255);
	if (i == 3)
		return (col.r * 300 / 255);
	return (0);
}

int			test6(int x)
{
	return (x * 255 / 300);
}

void		test2(t_fat *fact, t_col col)
{
	t_fat	fat;
	int		x;
	int		y;

	fat = *fact;
	y = 149;
	while (++y <= 200)
	{
		x = 49;
		while (++x <= 350)
		{
			if (x == 50 || y == 150 || x == 350 || y == 200)
				fat.mlx.img.data[y * W + x] = 1;
			else
				fat.mlx.img.data[y * W + x] =
					linear_interpolate(col, col, 0, 0.99);
		}
	}
}

void		test4(t_fat *fact, int x, int y)
{
	t_fat	fat;
	int		i;
	int		j;

	fat = *fact;
	j = y - 5;
	while (j <= y + 4)
	{
		i = x - 2;
		while (i <= x + 2)
		{
			if (j == y + 4 || j == y - 5)
				fat.mlx.img.data[j * W + i] = 0xffffff;
			if (i == x - 2 || i == x + 2 || i == x)
				fat.mlx.img.data[j * W + i] = 0xffffff;
			if (j > y - 4 && j < y + 3 && (i - 1 == x - 3))
				fat.mlx.img.data[j * W + i - 1] = 0xffffff;
			else if (j > y - 4 && j < y + 3 && i + 1 == x + 3)
				fat.mlx.img.data[j * W + i + 1] = 0xffffff;
			i++;
		}
		j++;
	}
}
