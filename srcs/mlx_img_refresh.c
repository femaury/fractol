/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_refresh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:42:43 by femaury           #+#    #+#             */
/*   Updated: 2018/07/07 19:01:42 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			img_refresh(t_mlx *env)
{
	if (!env->refresh)
		return (1);
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img.ptr);
	env->img.ptr = mlx_new_image(env->mlx, IMG_W, IMG_H);
	env->img.data = (unsigned int *)mlx_get_data_addr(env->img.ptr,
			&env->img.bpp, &env->img.ln_size, &env->img.endian);
	(*env->draw_fractal[env->fractal]) (env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
	env->refresh = 0;
	return (0);
}
