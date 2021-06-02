/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:33:46 by adandres          #+#    #+#             */
/*   Updated: 2019/01/23 17:11:09 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fat.h"

int			linear_interpolate(t_col col1, t_col col2, double t, double c)
{
	return (rgb((col1.r + t * (col2.r - col1.r)) * c, (col1.g + t *
				(col2.g - col1.g)) * c, (col1.b + t * (col2.b - col1.b)) * c));
}

int			mult_thread(t_fat *fact)
{
	t_thr	thread;
	int		i;
	void	*f;

	i = 0;
	f = wich_fract(fact);
	while (i < THREAD)
	{
		thread.env[i].tid = i;
		thread.env[i].fat = *fact;
		if (pthread_create(&thread.thread[i], NULL, f, &thread.env[i]))
			exit(1);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(thread.thread[i], NULL);
		i++;
	}
	return (0);
}

void		hook_it(t_fat f)
{
	mlx_put_image_to_window(f.mlx.mlx, f.mlx.win, f.mlx.img.img_ptr, 0, 0);
	mlx_hook(f.mlx.win, 4, 0, deal_mouse, &f);
	mlx_hook(f.mlx.win, 5, 0, deal_m, &f);
	mlx_hook(f.mlx.win, 6, 0, test_mouse, &f);
	mlx_hook(f.mlx.win, 2, 5, deal_key, &f);
	mlx_loop(f.mlx.mlx);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			init_fract2();
		if (ft_strcmp(av[1], "Mandel") == 0)
			init_fract1();
		if (ft_strcmp(av[1], "Ship") == 0)
			init_fract3();
		if (ft_strcmp(av[1], "Celtic") == 0)
			init_fract4();
	}
	write(1, "usage : ./fractol Julia/Mandel/Ship/Celtic\n", 43);
	return (0);
}
