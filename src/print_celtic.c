/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_celtic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 06:27:43 by adandres          #+#    #+#             */
/*   Updated: 2019/01/21 19:01:30 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

double			zr_zi_min(double a, double b)
{
	return (a * a - b * b);
}

void			add_on(int i, t_env *envlp)
{
	t_env env;

	env = *envlp;
	if (i < env.fat.var.i_max)
		fill_image_data(i, &env);
	else
		env.fat.mlx.img.data[(env.fat.pnt.y + env.fat.lim.y) * W +
			env.fat.pnt.x + env.fat.lim.x] = 1;
}

static void		calc_fract(t_env *envlp)
{
	t_env		env;
	int			i;
	double		tmp;
	double		t;

	env = *envlp;
	i = 0;
	while (zr_zi(env.fat.ire.z_r, env.fat.ire.z_i) < (1 << 16)
			&& i++ < env.fat.var.i_max)
	{
		tmp = zr_zi_min(env.fat.ire.z_r, env.fat.ire.z_i);
		tmp = fabs(tmp) + env.fat.ire.c_r;
		t = 2 * env.fat.ire.z_r * env.fat.ire.z_i + env.fat.ire.c_i;
		if (env.fat.ire.z_r == tmp && env.fat.ire.z_i == t)
		{
			i = env.fat.var.i_max;
			break ;
		}
		env.fat.ire.z_r = tmp;
		env.fat.ire.z_i = t;
	}
	add_on(i, &env);
}

void			print_fract4(t_env *envlp)
{
	t_env		env;

	env = *envlp;
	env.fat.pnt.y = env.fat.lim.h / THREAD * env.tid;
	while (env.fat.pnt.y < env.fat.lim.h / THREAD * (env.tid + 1))
	{
		env.fat.pnt.x = 0;
		while (env.fat.pnt.x < env.fat.lim.w)
		{
			env.fat.ire.c_r = env.fat.pnt.x / (env.fat.lim.w / (env.fat.rep.x2 -
						env.fat.rep.x1)) + env.fat.rep.x1 + env.fat.rep.m_x;
			env.fat.ire.c_i = env.fat.pnt.y / (env.fat.lim.h / (env.fat.rep.y2 -
						env.fat.rep.y1)) + env.fat.rep.y1 + env.fat.rep.m_y;
			env.fat.ire.z_i = 0;
			env.fat.ire.z_r = 0;
			calc_fract(&env);
			env.fat.pnt.x++;
		}
		env.fat.pnt.y++;
	}
	if (env.fat.onf.a && env.fat.onf.f == 4)
		print_ui(&env);
}
