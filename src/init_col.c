/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 03:18:36 by adandres          #+#    #+#             */
/*   Updated: 2018/10/05 15:14:37 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

t_col	fill_col(int a, int b, int c)
{
	t_col col;

	col.r = a;
	col.g = b;
	col.b = c;
	return (col);
}

t_col	what_col3(int i)
{
	if (i == 11)
		return (fill_col(248, 201, 95));
	if (i == 12)
		return (fill_col(255, 170, 0));
	if (i == 13)
		return (fill_col(204, 128, 0));
	if (i == 14)
		return (fill_col(153, 87, 0));
	return (fill_col(106, 52, 3));
}

t_col	what_col2(int i)
{
	if (i == 6)
		return (fill_col(24, 82, 177));
	if (i == 7)
		return (fill_col(57, 125, 209));
	if (i == 8)
		return (fill_col(134, 181, 229));
	if (i == 9)
		return (fill_col(211, 236, 248));
	if (i == 10)
		return (fill_col(241, 233, 191));
	return (what_col3(i));
}

t_col	what_col(int i)
{
	if (i == 0)
		return (fill_col(66, 30, 15));
	if (i == 1)
		return (fill_col(25, 7, 26));
	if (i == 2)
		return (fill_col(9, 1, 47));
	if (i == 3)
		return (fill_col(4, 4, 73));
	if (i == 4)
		return (fill_col(0, 7, 100));
	if (i == 5)
		return (fill_col(12, 44, 138));
	return (what_col2(i));
}

void	init_col(t_fat *fact)
{
	t_fat	fat;
	int		i;

	fat = *fact;
	i = 0;
	while (i < 16)
	{
		fact->col[i] = what_col(i);
		i++;
	}
}
