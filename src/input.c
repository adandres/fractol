/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                         /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 03:24:49 by adandres          #+#    #+#             */
/*   Updated: 2018/12/21 10:36:53 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

int		deal_mouse(int button, int x, int y, t_fat *fact)
{
	t_fat	fat;

	fat = *fact;
	if (button == 1 && x > 1200)
	{
		if (y > 0 && y < 401 && fat.onf.f == 1)
			fat.onf.f = 2;
		else if (y > 0 && y < 401)
			fat.onf.f = 1;
		if (y > 400 && y < 801 && fat.onf.f != 3 && fat.onf.f != 4)
			fat.onf.f = 3;
		else if (y > 400 && y < 801 && (fat.onf.f == 3 || fat.onf.f == 4))
			fat.onf.f = 2;
		else if (y > 800 && fat.onf.f != 4)
			fat.onf.f = 4;
		else if (y > 800)
			fat.onf.f = 3;
		init_var(&fat);
	}
	else if ((button == 1 || button == 5 || button == 4) && x <= 1200)
		deal_mouse2(button, x, y, fact);
	deal_fract(fat);
	return (0);
}

int		deal_m(int button, int x, int y, t_fat *fact)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		fact->onf.x1 = 0;
		fact->onf.x2 = 0;
		fact->onf.x3 = 0;
	}
	return (0);
}
