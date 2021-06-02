/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:01:13 by adandres          #+#    #+#             */
/*   Updated: 2019/01/23 17:06:26 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

void		*wich_fract(t_fat *fat)
{
	if (fat->var.f == 4)
		return (&print_fract4);
	else if (fat->var.f == 2)
		return (&print_fract2);
	else if (fat->var.f == 1)
		return (&print_fract1);
	else
		return (&print_fract3);
}

double		zr_zi(double a, double b)
{
	return (a * a + b * b);
}

void		fill_image_data(int i, t_env *envlp)
{
	t_env	env;
	double	l;
	double	tmp;

	env = *envlp;
	tmp = log(zr_zi(env.fat.ire.z_r, env.fat.ire.z_i)) / 2;
	l = log(tmp / log(2)) / log(2);
	tmp = i + 1 - l;
	l = -1 * (H / 3) + env.fat.pnt.y + 8;
	if (l < 0)
		l = 0;
	if (env.fat.pnt.y > 100 && env.fat.pnt.y < 150 && env.fat.pnt.x > 368 &&
	env.fat.pnt.x < 386 && env.fat.onf.a == 1 && env.fat.var.f == env.fat.onf.f)
		env.fat.mlx.img.data[env.fat.pnt.y * (W) + env.fat.pnt.x] =
			linear_interpolate(env.fat.col[i % 16], env.fat.col[(i + 1) % 16],
					tmp - (int)tmp, 0.2);
	else if (env.fat.pnt.y < H / 3 && env.fat.pnt.x < 100 - l +
			(100 * env.fat.onf.a * 3) && env.fat.var.f == env.fat.onf.f)
		env.fat.mlx.img.data[env.fat.pnt.y * (W) + env.fat.pnt.x] =
			linear_interpolate(env.fat.col[i % 16],
					env.fat.col[(i + 1) % 16], tmp - (int)tmp, 0.5);
	else
		env.fat.mlx.img.data[(env.fat.pnt.y + env.fat.lim.y) * (W) +
		env.fat.pnt.x + env.fat.lim.x] = linear_interpolate(env.fat.col[i % 16],
					env.fat.col[(i + 1) % 16], tmp - (int)tmp, 0.99);
}

void		print_ui(t_env *envlp)
{
	t_env env;

	env = *envlp;
	test(&env.fat);
	if (env.fat.onf.b)
	{
		test2(&env.fat, env.fat.onf.c);
		test3(&env.fat, 250);
		if (env.fat.onf.x1)
			test4(&env.fat, env.fat.onf.x1, 254);
		else
			test4(&env.fat, test5(env.fat.onf.c, 1) + 50, 254);
		test3(&env.fat, 300);
		if (env.fat.onf.x2)
			test4(&env.fat, env.fat.onf.x2, 304);
		else
			test4(&env.fat, test5(env.fat.onf.c, 2) + 50, 304);
		test3(&env.fat, 350);
		if (env.fat.onf.x3)
			test4(&env.fat, env.fat.onf.x3, 354);
		else
			test4(&env.fat, test5(env.fat.onf.c, 3) + 50, 354);
	}
}
