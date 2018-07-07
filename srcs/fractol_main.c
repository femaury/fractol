/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:56:14 by femaury           #+#    #+#             */
/*   Updated: 2018/07/07 19:13:24 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_arguments(int ac, char **av, t_mlx *env)
{
	if (ac != 2)
	{
		ft_printf("usage: ./fractol fractal_name\nSupported fractals:\n"
				"%20s%s\n%20s%s\n%20s%s\n", "", "Julia", "",
				"Mandelbrot", "", "Other");
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp("Julia", av[1]) || !ft_strcmp("julia", av[1]))
		env->fractal = 0;
	else if (!ft_strcmp("Mandelbrot", av[1]) || !ft_strcmp("mandelbrot", av[1]))
		env->fractal = 1;
	else if (!ft_strcmp("Other", av[1]) || !ft_strcmp("other", av[1]))
		env->fractal = 2;
	else
		{
			ft_printf("usage: ./fractol fractal_name\nSupported fractals:\n"
					"%20s%s\n%20s%s\n%20s%s\n", "", "Julia", "", 
					"Mandelbrot", "", "Other");
			exit(EXIT_FAILURE);
		}
}

static void	init_env(t_mlx *env)
{
	env->max_iter = 200;
	env->refresh = 0;
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
	exit(EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	t_mlx	env;

	init_env(&env);
	check_arguments(ac, av, &env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, "Fract'ol");
	env.img.ptr = mlx_new_image(env.mlx, IMG_W, IMG_H);
	env.img.data = (unsigned int *)mlx_get_data_addr(env.img.ptr,
			&env.img.bpp, &env.img.ln_size, &env.img.endian);
	(*env.draw_fractal[env.fractal]) (&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.ptr, 0, 0);
	mlx_key_hook(env.win, hook_keypress, &env);
	mlx_mouse_hook(env.win, hook_mousepress, &env);
	mlx_hook(env.win, 17, 0, click_close, &env);
	mlx_loop_hook(env.mlx, img_refresh, &env);
	mlx_loop(env.mlx);
	return (0);
}
