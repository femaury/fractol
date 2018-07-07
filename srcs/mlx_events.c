/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:52:10 by femaury           #+#    #+#             */
/*   Updated: 2018/07/07 18:16:33 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_env(t_mlx *env)
{
	env->zoom = 1;
	env->pad_x = 0;
	env->pad_y = 0;
	env->c.r = -0.7;
	env->c.i = 0.27015;
}

static void	change_fractal(t_mlx *env, int keycode)
{
	if (keycode == K1_KEY || keycode == NK1_KEY)
		env->fractal = 0;
	else if (keycode == K2_KEY || keycode == NK2_KEY)
		env->fractal = 1;
	else if (keycode == K3_KEY || keycode == NK3_KEY)
		env->fractal = 2;
	reset_env(env);
}

int			hook_keypress(int keycode, t_mlx *env)
{
	if (keycode == PL_KEY || keycode == NKPL_KEY)
		env->zoom += 2 * env->zoom;
	else if (keycode == MN_KEY || keycode == NKMN_KEY)
		env->zoom -= env->zoom > 1 ? env->zoom / 2 : 0;
	else if (keycode == UP_KEY)
		env->pad_y -= 1.0 / (env->zoom * 2);
	else if (keycode == DOWN_KEY)
		env->pad_y += 1.0 / (env->zoom * 2);
	else if (keycode == RIGHT_KEY)
		env->pad_x += 1.0 / (env->zoom * 2);
	else if (keycode == LEFT_KEY)
		env->pad_x -= 1.0 / (env->zoom * 2);
	else if (keycode == K1_KEY || keycode == K2_KEY || keycode == K3_KEY
			|| keycode == NK1_KEY || keycode == NK2_KEY || keycode ==  NK3_KEY)
		change_fractal(env, keycode);
	else if (keycode == CLR_KEY)
		reset_env(env);
	else if (keycode == ESC_KEY)
		exit(EXIT_SUCCESS);
	env->refresh = 1;
	return (0);
}
