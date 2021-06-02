/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:37:58 by adandres          #+#    #+#             */
/*   Updated: 2018/10/08 11:58:05 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

void		fract_julia(t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	fat.var.f = 2;
	if (fat.onf.f != 2)
	{
		fat.rep.x1 = -2;
		fat.rep.x2 = 2;
		fat.rep.y1 = -2;
		fat.rep.y2 = 2;
		fat.ire.c_r = -0.165;
		fat.ire.c_i = 0.76;
		fat.lim.x = 1200;
		fat.lim.y = 0;
		if (fat.onf.f != 1)
			fat.lim.y = 400;
		fat.lim.w = 400;
		fat.lim.h = 400;
		fat.rep.m_x = 0;
		fat.rep.m_y = 0;
	}
	else
		help_init(&fat);
	mult_thread(&fat);
}

void		fract_ship(t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	fat.var.f = 3;
	if (fat.onf.f != 3)
	{
		fat.rep.x1 = -3.2;
		fat.rep.x2 = 0.8;
		fat.rep.y1 = -2;
		fat.rep.y2 = 2;
		fat.lim.x = 1200;
		if (fat.onf.f != 4)
			fat.lim.y = 400;
		else
			fat.lim.y = 800;
		fat.lim.w = 400;
		fat.lim.h = 400;
		fat.rep.m_x = 0;
		fat.rep.m_y = 0;
	}
	else
		help_init(&fat);
	mult_thread(&fat);
}

void		fract_mandel(t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	fat.var.f = 1;
	if (fat.onf.f != 1)
	{
		fat.rep.x1 = -2.5;
		fat.rep.x2 = 1.5;
		fat.rep.y1 = -2;
		fat.rep.y2 = 2;
		fat.lim.y = 0;
		fat.lim.x = 1200;
		fat.lim.w = 400;
		fat.lim.h = 400;
		fat.rep.m_x = 0;
		fat.rep.m_y = 0;
	}
	else
	{
		fat.lim.y = 0;
		fat.lim.x = 0;
		fat.lim.w = W - 400;
		fat.lim.h = H;
	}
	mult_thread(&fat);
}

void		fract_celtic(t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	fat.var.f = 4;
	if (fat.onf.f != 4)
	{
		fat.rep.x1 = -2.5;
		fat.rep.x2 = 1.5;
		fat.rep.y1 = -2;
		fat.rep.y2 = 2;
		fat.lim.y = 800;
		fat.lim.x = 1200;
		fat.lim.w = 400;
		fat.lim.h = 400;
		fat.rep.m_x = 0;
		fat.rep.m_y = 0;
	}
	else
	{
		fat.lim.y = 0;
		fat.lim.x = 0;
		fat.lim.w = W - 400;
		fat.lim.h = H;
	}
	mult_thread(&fat);
}

void		help_init(t_fat *fact)
{
	fact->lim.y = 0;
	fact->lim.x = 0;
	fact->lim.w = W - 400;
	fact->lim.h = H;
}
