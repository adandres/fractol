/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:28:53 by adandres          #+#    #+#             */
/*   Updated: 2019/01/21 19:00:54 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

static void		calc_fract(t_env *envlp)
{
	t_env		env;
	double		tmp;
	int			i;

	env = *envlp;
	i = 0;
	while (zr_zi(env.fat.ire.z_r, env.fat.ire.z_i) < (1 << 16)
			&& i < env.fat.var.i_max)
	{
		tmp = zr_zi_min(env.fat.ire.z_r, env.fat.ire.z_i) +
			env.fat.ire.c_r + 1.1;
		env.fat.ire.z_i = fabs(2 * env.fat.ire.z_r * env.fat.ire.z_i) +
			env.fat.ire.c_i - 0.6;
		env.fat.ire.z_r = tmp;
		i++;
	}
	add_on(i, &env);
}

void			print_fract3(t_env *envlp)
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
	if (env.fat.onf.a && env.fat.onf.f == 3)
		print_ui(&env);
}
