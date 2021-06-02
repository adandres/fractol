/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                    /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:10:19 by adandres          #+#    #+#             */
/*   Updated: 2020/06/25 19:48:56 by adandres                                 */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

void		deal_key3(int key, t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	if (key == 33 && fat.var.j_coef > 1) // ^
		fat.var.j_coef--;
	else if (key == 30 && fat.var.j_coef <= 19) // $
		fat.var.j_coef++;
	else if (key == 124) // gauche 
		fat.var.i_max += 10;
	else if (key == 123 && fat.var.i_max > 10) // droite
		fat.var.i_max -= 10;
	else if (key == 2)
		fat.rep.m_x += (0.1 * fat.rep.zoom);
	else if (key == 0)
		fat.rep.m_x -= (0.1 * fat.rep.zoom);
	else if (key == 1)
		fat.rep.m_y += (0.1 * fat.rep.zoom);
	else if (key == 13)
		fat.rep.m_y -= (0.1 * fat.rep.zoom);
	deal_fract(fat);
}

void		deal_key2(int key, t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	if (key == 38 && fat.var.julia_buffer == 1) // j
		fat.var.julia_buffer = 0;
	else if (key == 38) // j
		fat.var.julia_buffer = 1;
	else if (key == 49) // espace
		init_var(&fat);
	else if (key == 36) // enter
	{
		fat.onf.b = 0;
		init_col(&fat);
	}
	else if (key == 53)
	{
		mlx_destroy_window(fat.mlx.mlx, fat.mlx.win);
		exit(1);
	}
	else
		deal_key3(key, fact);
	deal_fract(fat);
}

int			deal_key(int key, t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	printf("%d\n", key);
	if (key == 125) //haut
	{
		fat.rep.x1 *= 1.1;
		fat.rep.x2 *= 1.1;
		fat.rep.y1 *= 1.1;
		fat.rep.y2 *= 1.1;
		fat.rep.zoom *= 1.1;
	}
	else if (key == 126) // bas
	{
		fat.rep.zoom /= 1.1;
		fat.rep.x1 /= 1.1;
		fat.rep.x2 /= 1.1;
		fat.rep.y1 /= 1.1;
		fat.rep.y2 /= 1.1;
	}
	else
		deal_key2(key, fact);
	deal_fract(fat);
	return (0);
}

void		test_mouse2(int x, t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	if (x < 50)
		x = 50;
	if (x > 350)
		x = 350;
	if (fat.onf.x1)
	{
		fat.onf.x1 = x;
		fat.onf.c.b = test6(fat.onf.x1 - 50);
	}
	if (fat.onf.x2)
	{
		fat.onf.x2 = x;
		fat.onf.c.g = test6(fat.onf.x2 - 50);
	}
	if (fat.onf.x3)
	{
		fat.onf.x3 = x;
		fat.onf.c.r = test6(fat.onf.x3 - 50);
	}
	if (fat.onf.x1 || fat.onf.x2 || fat.onf.x3)
		fat.col[fat.onf.i] = fat.onf.c;
	deal_fract(fat);
}

int			test_mouse(int x, int y, t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	if (fat.var.f == 2 && fat.var.julia_buffer != 0 && (x > 100 + (100 *
					fat.onf.a * 3) || y > H / 3) && x < 1200)
	{
		if (x < fat.var.s_x)
			fat.ire.c_i += 0.001 * fat.var.j_coef;
		if (x > fat.var.s_x)
			fat.ire.c_i -= 0.001 * fat.var.j_coef;
		if (y < fat.var.s_y)
			fat.ire.c_r += 0.001 * fat.var.j_coef;
		if (y > fat.var.s_y)
			fat.ire.c_r -= 0.001 * fat.var.j_coef;
		fat.var.s_x = x;
		fat.var.s_y = y;
	}
	else
		test_mouse2(x, fact);
	deal_fract(fat);
	return (0);
}
