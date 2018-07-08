/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 02:30:59 by femaury           #+#    #+#             */
/*   Updated: 2018/07/08 01:58:11 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_mlx *env)
{
	int			x;
	int			y;
	int			i;
	t_complex	new;
	t_complex	old;

	y = -1;
	while ((x = -1) && ++y < IMG_H)
		while ((i = -1) && ++x < IMG_W)
		{
			new.r = 1.5 * ((double)x - IMG_W / 2.0)
				/ (0.5 * env->zoom * IMG_W) + env->pad_x;
			new.i = ((double)y - IMG_H / 2.0)
				/ (0.5 * env->zoom * IMG_H) + env->pad_y;
			while (++i < env->max_iter
					&& (new.r * new.r + new.i * new.i <= 4))
			{
				old.r = new.r;
				old.i = new.i;
				new.r = (old.r * old.r) - (old.i * old.i) + env->c.r;
				new.i = 2 * old.r * old.i + env->c.i;
			}
			env->img.data[y * IMG_W + x] = get_color(i, env->max_iter);
		}
}
