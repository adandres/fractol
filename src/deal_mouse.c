/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:23:34 by adandres          #+#    #+#             */
/*   Updated: 2018/12/21 11:07:36 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

static void		deal_mouse6(int x, int y, t_fat *fact)
{
	t_fat		fat;

	fat = *fact;
	if (fat.onf.b == 1 && y > 150 && y < 200 && x > 50 && x < 350 && !fat.onf.d)
		fat.onf.d = 1;
	else if (y > 150 && y < 200 && fat.onf.d && x < 350 && x > 50)
		fat.onf.d = 0;
	else if (y > 100 && y < 150 && x > 50 && x < 350 && fat.onf.a == 1 &&
			fat.onf.d == 1)
	{
		fat.col[(x - 50) * 16 / 300] = fat.onf.c;
		fat.onf.d = 0;
	}
	else if (fat.onf.a == 1 && !((y > 248 && y < 264 && x > 40 && x < 355 &&
		fat.onf.b) || (y > 298 && y < 314 && x > 45 && x < 355 && fat.onf.b) ||
		(y > 348 && y < 364 && x > 45 && x < 355 && fat.onf.b) ||
		(fat.onf.b && y > 150 && y < 200 && x > 50 && x < 350)))
	{
		fat.onf.a = 0;
		fat.onf.b = 0;
		fat.onf.d = 0;
	}
	deal_fract(fat);
}

static void		deal_mouse5(int x, int y, t_fat *fact)
{
	t_fat		fat;

	fat = *fact;
	if (y > 100 && y < 150 && x > 50 && x < 350 && fat.onf.a == 1 &&
			fat.onf.d == 0)
	{
		fat.onf.b = 1;
		fat.onf.c = fat.col[(x - 50) * 16 / 300];
		fat.onf.i = (x - 50) * 16 / 300;
	}
	else if (fat.onf.b == 1 && (y > 350 && y < 360) && x > 48 && x < 352)
	{
		fat.onf.x3 = x;
		fat.onf.c.r = test6(fat.onf.x3 - 50);
		fat.col[fat.onf.i] = fat.onf.c;
		fat.onf.d = 0;
	}
	else
		deal_mouse6(x, y, fact);
	deal_fract(fat);
}

static void		deal_mouse4(int x, int y, t_fat *fact)
{
	t_fat		fat;

	fat = *fact;
	if (fat.onf.b == 1 && y > 250 && y < 260 && x > 48 && x < 352)
	{
		fat.onf.x1 = x;
		fat.onf.c.b = test6(fat.onf.x1 - 50);
		fat.col[fat.onf.i] = fat.onf.c;
		fat.onf.d = 0;
	}
	else if (fat.onf.b == 1 && (y > 300 && y < 310) && x > 48 && x < 352)
	{
		fat.onf.x2 = x;
		fat.onf.c.g = test6(fat.onf.x2 - 50);
		fat.col[fat.onf.i] = fat.onf.c;
		fat.onf.d = 0;
	}
	else if (fat.onf.a == 0)
		fat.onf.a = 1;
	else
		deal_mouse5(x, y, fact);
	deal_fract(fat);
}

static void		deal_mouse3(int x, int y, t_fat *fact)
{
	t_fat		fat;

	fat = *fact;
	if (x >= 100 + (100 * fat.onf.a * 4) || y > H / 3)
	{
		fat.onf.a = 0;
		fat.onf.b = 0;
		fat.onf.d = 0;
		fat.rep.m_x -= (fat.rep.x1 - fat.rep.x2) / (1200) * (x - (1200) / 1.7);
		fat.rep.m_y -= (fat.rep.y1 - fat.rep.y2) / (H) * (y - H / 2);
		fat.rep.x1 /= 1.5;
		fat.rep.x2 /= 1.5;
		fat.rep.y1 /= 1.5;
		fat.rep.y2 /= 1.5;
		fat.rep.zoom /= 1.5;
	}
	else if (fat.onf.b == 1 && y > 100 && y < 150 && x > 368 && x < 386)
	{
		fat.col[fat.onf.i] = what_col(fat.onf.i);
		fat.onf.b = 0;
		fat.onf.d = 0;
	}
	else
		deal_mouse4(x, y, fact);
	deal_fract(fat);
}

void			deal_mouse2(int button, int x, int y, t_fat *fact)
{
	t_fat		fat;

	fat = *fact;
	if (button == 1 && x <= 1200)
		deal_mouse3(x, y, fact);
	else if (button == 5)
	{
		fat.rep.zoom /= 1.5;
		fat.rep.x1 /= 1.5;
		fat.rep.x2 /= 1.5;
		fat.rep.y1 /= 1.5;
		fat.rep.y2 /= 1.5;
		fat.rep.m_x -= (fat.rep.x1 - fat.rep.x2) / (1200) * (x - (1200) / 1.7);
		fat.rep.m_y -= (fat.rep.y1 - fat.rep.y2) / (H) * (y - H / 2);
	}
	else if (button == 4)
	{
		fat.rep.zoom *= 1.1;
		fat.rep.x1 *= 1.1;
		fat.rep.x2 *= 1.1;
		fat.rep.y1 *= 1.1;
		fat.rep.y2 *= 1.1;
	}
	deal_fract(fat);
}
