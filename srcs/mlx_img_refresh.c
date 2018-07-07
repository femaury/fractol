/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_refresh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:42:43 by femaury           #+#    #+#             */
/*   Updated: 2018/07/04 23:53:32 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_env(t_mlx *env)
{
	env->zoom = 1;
	env->pad_x = 0;
	env->pad_y = 0;
}

static void	modify_env(t_mlx *env)
{
	if (env->keydown == PL_KEY || env->keydown == NKPL_KEY)
		env->zoom += 2 * env->zoom;
	else if (env->keydown == MN_KEY || env->keydown == NKMN_KEY)
		env->zoom -= env->zoom > 1 ? env->zoom / 2 : 0;
	else if (env->keydown == UP_KEY)
		env->pad_y += 1.0 / (env->zoom * 2);
	else if (env->keydown == DOWN_KEY)
		env->pad_y -= 1.0 / (env->zoom * 2);
	else if (env->keydown == RIGHT_KEY)
		env->pad_x -= 1.0 / (env->zoom * 2);
	else if (env->keydown == LEFT_KEY)
		env->pad_x += 1.0 / (env->zoom * 2);
	else if (env->keydown == K1_KEY || env->keydown == NK1_KEY)
		env->fractal = 0;
	else if (env->keydown == K2_KEY || env->keydown == NK2_KEY)
		env->fractal = 1;
	else if (env->keydown == K3_KEY || env->keydown == NK3_KEY)
		env->fractal = 2;

}

int			img_refresh(t_mlx *env)
{
	if (!env->keydown)
		return (1);
	if (env->keydown == ESC_KEY)
		exit(EXIT_SUCCESS);
	if (env->keydown == CLR_KEY)
		reset_env(env);
	if (env->keydown)
		modify_env(env);
	if (env->fractal == -1)
		return (1);
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img.ptr);
	env->img.ptr = mlx_new_image(env->mlx, IMG_W, IMG_H);
	env->img.data = (unsigned int *)mlx_get_data_addr(env->img.ptr,
			&env->img.bpp, &env->img.ln_size, &env->img.endian);
	(*env->draw_fractal[env->fractal]) (env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
	return (0);
}
