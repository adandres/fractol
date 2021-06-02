/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_fract.c                                    /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:40:49 by adandres          #+#    #+#             */
/*   Updated: 2019/01/23 17:11:05 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

void	deal_fract2(t_fat fat)
{
	if (fat.onf.f == 3)
	{
		fract_ship(&fat);
		fract_mandel(&fat);
		fract_julia(&fat);
		fract_celtic(&fat);
		fat.var.f = 3;
		hook_it(fat);
	}
	if (fat.onf.f == 4)
	{
		fract_celtic(&fat);
		fract_mandel(&fat);
		fract_julia(&fat);
		fract_ship(&fat);
		fat.var.f = 4;
		hook_it(fat);
	}
}

void	deal_fract(t_fat fat)
{
	if (fat.onf.f == 1)
	{
		fract_mandel(&fat);
		fract_julia(&fat);
		fract_ship(&fat);
		fract_celtic(&fat);
		fat.var.f = 1;
		hook_it(fat);
	}
	else if (fat.onf.f == 2)
	{
		fract_julia(&fat);
		fract_mandel(&fat);
		fract_ship(&fat);
		fract_celtic(&fat);
		fat.var.f = 2;
		hook_it(fat);
	}
	else
		deal_fract2(fat);
}

void	init_var2(t_fat *fat)
{
	if (fat->onf.f == 1 || fat->onf.f == 4)
	{
		fat->rep.x1 = -2.5;
		fat->rep.x2 = 1.5;
		fat->rep.y1 = -2;
		fat->rep.y2 = 2;
	}
	if (fat->onf.f == 2)
	{
		fat->rep.x1 = -2;
		fat->rep.x2 = 2;
		fat->rep.y1 = -2;
		fat->rep.y2 = 2;
		fat->ire.c_r = -0.165;
		fat->ire.c_i = 0.76;
	}
	if (fat->onf.f == 3)
	{
		fat->rep.x1 = -3.2;
		fat->rep.x2 = 0.8;
		fat->rep.y1 = -2;
		fat->rep.y2 = 2;
	}
}

void	init_var(t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	fat.onf.a = 0;
	fat.onf.b = 0;
	fat.onf.d = 0;
	fat.rep.m_y = 0;
	fat.rep.m_x = 0;
	fat.var.i_max = 100;
	fat.var.s_x = (W - 400) / 2;
	fat.var.s_y = H / 2;
	fat.rep.zoom = 1;
	fat.var.julia_buffer = 1;
	fat.var.j_coef = 1;
	init_var2(&fat);
	*fact = fat;
}
