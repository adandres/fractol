/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:31:13 by adandres          #+#    #+#             */
/*   Updated: 2019/01/23 17:10:48 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

int			init_fract1(void)
{
	t_fat	fat;

	fat.onf.f = 1;
	fat.var.i_max = 100;
	fat.var.s_x = (W - 400) / 2;
	fat.var.s_y = H / 2;
	fat.rep.zoom = 1;
	fat.rep.m_x = 0;
	fat.rep.x1 = -2.5;
	fat.rep.x2 = 1.5;
	fat.rep.y1 = -2;
	fat.rep.y2 = 2;
	fat.rep.m_y = 0;
	init_col(&fat);
	fat.mlx.mlx = mlx_init();
	fat.mlx.win = mlx_new_window(fat.mlx.mlx, W, H, "fractol");
	fat.mlx.img.img_ptr = mlx_new_image(fat.mlx.mlx, W, H);
	fat.mlx.img.data = (int *)mlx_get_data_addr(fat.mlx.img.img_ptr,
			&fat.mlx.img.bpp, &fat.mlx.img.size_l, &fat.mlx.img.endian);
	deal_fract(fat);
	return (0);
}

int			init_fract4(void)
{
	t_fat	fat;

	fat.onf.f = 4;
	fat.var.i_max = 100;
	fat.var.s_x = (W - 400) / 2;
	fat.var.s_y = H / 2;
	fat.rep.zoom = 1;
	fat.rep.m_x = 0;
	fat.rep.x1 = -2.5;
	fat.rep.x2 = 1.5;
	fat.rep.y1 = -2;
	fat.rep.y2 = 2;
	fat.rep.m_y = 0;
	init_col(&fat);
	fat.mlx.mlx = mlx_init();
	fat.mlx.win = mlx_new_window(fat.mlx.mlx, W, H, "fractol");
	fat.mlx.img.img_ptr = mlx_new_image(fat.mlx.mlx, W, H);
	fat.mlx.img.data = (int *)mlx_get_data_addr(fat.mlx.img.img_ptr,
			&fat.mlx.img.bpp, &fat.mlx.img.size_l, &fat.mlx.img.endian);
	deal_fract(fat);
	return (0);
}

int			init_fract3(void)
{
	t_fat	fat;

	fat.onf.f = 3;
	fat.var.i_max = 100;
	fat.var.s_x = (W - 400) / 2;
	fat.var.s_y = H / 2;
	fat.rep.zoom = 1;
	fat.rep.m_x = 0;
	fat.rep.x1 = -3.2;
	fat.rep.x2 = 0.8;
	fat.rep.y1 = -2;
	fat.rep.y2 = 2;
	fat.rep.m_y = 0;
	init_col(&fat);
	fat.mlx.mlx = mlx_init();
	fat.mlx.win = mlx_new_window(fat.mlx.mlx, W, H, "fractol");
	fat.mlx.img.img_ptr = mlx_new_image(fat.mlx.mlx, W, H);
	fat.mlx.img.data = (int *)mlx_get_data_addr(fat.mlx.img.img_ptr,
			&fat.mlx.img.bpp, &fat.mlx.img.size_l, &fat.mlx.img.endian);
	deal_fract(fat);
	return (0);
}

int			init_fract2(void)
{
	t_fat	fat;

	fat.onf.f = 2;
	fat.var.julia_buffer = 1;
	fat.var.j_coef = 1;
	fat.var.i_max = 100;
	fat.var.s_x = (W - 400) / 2;
	fat.var.s_y = H / 2;
	fat.rep.zoom = 1;
	fat.rep.m_x = 0;
	fat.rep.x1 = -2;
	fat.rep.x2 = 2;
	fat.rep.y1 = -2;
	fat.rep.y2 = 2;
	fat.ire.c_r = -0.165;
	fat.ire.c_i = 0.76;
	fat.rep.m_y = 0;
	init_col(&fat);
	fat.mlx.mlx = mlx_init();
	fat.mlx.win = mlx_new_window(fat.mlx.mlx, W, H, "fractol");
	fat.mlx.img.img_ptr = mlx_new_image(fat.mlx.mlx, W, H);
	fat.mlx.img.data = (int *)mlx_get_data_addr(fat.mlx.img.img_ptr,
			&fat.mlx.img.bpp, &fat.mlx.img.size_l, &fat.mlx.img.endian);
	deal_fract(fat);
	return (0);
}
