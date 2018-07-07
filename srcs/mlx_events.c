/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:52:10 by femaury           #+#    #+#             */
/*   Updated: 2018/07/07 19:01:26 by femaury          ###   ########.fr       */
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
	env->max_iter = 200;
}

int			hook_keypress(int keycode, t_mlx *env)
{
	if (keycode == PL_KEY || keycode == NKPL_KEY)
		env->zoom += 0.5 * env->zoom;
	else if (keycode == MN_KEY || keycode == NKMN_KEY)
		env->zoom -= env->zoom > 1 ? 0.5 * env->zoom : 0;
	else if (keycode == UP_KEY)
		env->pad_y -= 1.0 / (env->zoom * 2);
	else if (keycode == DOWN_KEY)
		env->pad_y += 1.0 / (env->zoom * 2);
	else if (keycode == RIGHT_KEY)
		env->pad_x += 1.0 / (env->zoom * 2);
	else if (keycode == LEFT_KEY)
		env->pad_x -= 1.0 / (env->zoom * 2);
	else if (keycode == PUP_KEY)
		env->max_iter += 50;
	else if (keycode == PDOWN_KEY)
		env->max_iter -= env->max_iter == 50 ? 0 : 50;
	else if (keycode == CLR_KEY)
		reset_env(env);
	else if (keycode == ESC_KEY)
		exit(EXIT_SUCCESS);
	env->refresh = 1;
	return (0);
}
