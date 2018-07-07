/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:52:10 by femaury           #+#    #+#             */
/*   Updated: 2018/07/04 03:00:09 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			hook_keydown(int keycode, t_mlx *env)
{
	env->keydown = keycode;
	return (0);
}

int			hook_keyup(int keycode, t_mlx *env)
{
	(void)keycode;
	env->keydown = 0;
	return (0);
}
