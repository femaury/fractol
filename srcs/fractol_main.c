/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:56:14 by femaury           #+#    #+#             */
/*   Updated: 2018/07/05 00:03:54 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_env(t_mlx *env)
{
	env->fractal = -1;
	env->keydown = 0;
	env->zoom = 1;
	env->pad_x = 0;
	env->pad_y = 0;
	env->c.r = -0.7;
	env->c.i = 0.27015;
	env->draw_fractal[0] = draw_julia;
	env->draw_fractal[1] = draw_mandelbrot;
	env->draw_fractal[2] = draw_image;
}

static int	click_close(t_mlx *env)
{
	(void)env;
	exit(1);
}

int			main(void)
{
	t_mlx	env;

	init_env(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, "Fract'ol");
	env.img.ptr = mlx_new_image(env.mlx, IMG_W, IMG_H);
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	mlx_string_put(env.mlx, env.win, WIN_W / 2 - 100, 20, 0xFFFFFF, "Choose your fractal");
	mlx_string_put(env.mlx, env.win, 50, 50, 0xFFFFFF, "JULIA (1)");
	mlx_string_put(env.mlx, env.win, (WIN_W - 140) / 2, 50, 0xFFFFFF, "MANDELBROT (2)");
	mlx_string_put(env.mlx, env.win, WIN_W - 140, 50, 0xFFFFFF, "OTHER (3)");
	mlx_hook(env.win, 2, 0, hook_keydown, &env);
	mlx_hook(env.win, 3, 0, hook_keyup, &env);
	mlx_hook(env.win, 17, 0, click_close, &env);
	mlx_loop_hook(env.mlx, img_refresh, &env);
	mlx_loop(env.mlx);
	return (0);
}
