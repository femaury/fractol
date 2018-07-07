/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:49:58 by femaury           #+#    #+#             */
/*   Updated: 2018/07/05 00:08:17 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
**	----------------------------- SYSTEM LIBRARIES -----------------------------
*/

# include <math.h>

/*
**	------------------------------- MY LIBRARIES -------------------------------
*/

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_keycodes.h"
# include "../libft/incs/libft.h"

/*
**	--------------------------------- DEFINES ----------------------------------
*/

# define WIN_W 800
# define WIN_H 450
# define IMG_W WIN_W
# define IMG_H WIN_H
# define MAX_ITER 400

/*
**	-------------------------------- STRUCTURES --------------------------------
*/

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct	s_img
{
	int				bpp;
	int				ln_size;
	int				endian;
	void			*ptr;
	unsigned int	*data;

}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	char		*win_name;
	t_img		img;
	int			keydown;
	int			fractal;
	double		pad_x;
	double		pad_y;
	double		zoom;
	t_complex	c;
	void		(*draw_fractal[3]) (struct s_mlx *env);
}				t_mlx;

/*
**	----------------------------- FRACTOL FUNCTIONS ----------------------------
*/

int				hook_keydown(int keycode, t_mlx *env);
int				hook_keyup(int keycode, t_mlx *env);
int				img_refresh(t_mlx *env);
int				get_color(int i);
void			draw_image(t_mlx *env);
void			draw_julia(t_mlx *env);
void			draw_mandelbrot(t_mlx *env);

#endif
