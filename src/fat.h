/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.h                                           /       \.'`  `',.--//   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:19:00 by adandres          #+#    #+#             */
/*   Updated: 2020/06/25 19:31:15 by adandres                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAT_H
# define FAT_H

# include "/usr/X11/include/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# define W 1600
# define H 1200
# define THREAD 20
# include "../libft/libft.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
}				t_col;

typedef struct	s_onf
{
	int			f;
	int			a;
	int			b;
	int			d;
	int			i;
	int			x1;
	int			x2;
	int			x3;
	t_col		c;
}				t_onf;

typedef struct	s_pnt
{
	int		x;
	int		y;
}				t_pnt;

typedef struct	s_lim
{
	int		w;
	int		h;
	int		x;
	int		y;
}				t_lim;

typedef struct	s_ire
{
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
}				t_ire;

typedef struct	s_var
{
	int		k;
	int		f;
	int		i_max;
	int		s_x;
	int		s_y;
	int		j_coef;
	int		julia_buffer;
}				t_var;

typedef struct	s_rep
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom;
	double	m_x;
	double	m_y;
}				t_rep;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;

typedef struct	s_fat
{
	t_mlx		mlx;
	t_rep		rep;
	t_var		var;
	t_ire		ire;
	t_pnt		pnt;
	t_onf		onf;
	t_lim		lim;
	t_col		col[16];
}				t_fat;

typedef struct	s_env
{
	int		tid;
	t_fat	fat;
}				t_env;

typedef	struct	s_thr
{
	pthread_t	thread[THREAD];
	t_env		env[THREAD];
}				t_thr;

void			add_on(int i, t_env *envlp);
double			zr_zi_min(double a, double b);
double			zr_zi(double a, double b);
int				init_fract1(void);
int				init_fract2(void);
int				init_fract3(void);
int				deal_key(int key, t_fat *fact);
int				test_mouse(int x, int y, t_fat *fact);
int				deal_mouse(int button, int x, int y, t_fat *fact);
int				mult_thread(t_fat *fact);
int				linear_interpolate(t_col col1, t_col col2, double t, double c);
int				rgb(int a, int b, int c);
void			*wich_fract(t_fat *fat);
void			print_fract2(t_env *envlp);
void			init_col(t_fat *fact);
void			help_init(t_fat *fact);
void			print_fract1(t_env *envlp);
void			print_fract2(t_env *envlp);
void			print_fract3(t_env *envlp);
void			print_fract4(t_env *envlp);
void			fract_mandel(t_fat *fact);
void			fract_julia(t_fat *fact);
void			fract_ship(t_fat *fact);
void			fract_celtic(t_fat *fact);
void			init_col(t_fat *fact);
void			hook_it(t_fat fat);
void			print_info(t_fat fat);
void			print_ui(t_env *envlp);
void			fill_image_data(int i, t_env *envlp);
void			deal_mouse2(int button, int x, int y, t_fat *fact);
void			test(t_fat *fact);
int				test5(t_col col, int i);
void			test2(t_fat *fact, t_col col);
void			test3(t_fat *fact, int i);
void			test4(t_fat *fact, int x, int y);
int				init_fract4(void);
void			deal_fract(t_fat fat);
void			init_var(t_fat *fact);
int				deal_m(int button, int x, int y, t_fat *fact);
t_col			what_col(int i);
int				test6(int a);

#endif
