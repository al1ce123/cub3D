/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:58 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:32 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_rays_init(t_data *d)
{
	d->dof = 0;
	d->dish = 1000000;
	d->hx = d->px;
	d->hy = d->py;
	d->atan = -1 / tan(d->ra);
}

void	draw_rays_init2(t_data *d)
{
	d->dof = 0;
	d->disv = 1000000;
	d->vx = d->px;
	d->vy = d->py;
	d->ntan = -tan(d->ra);
}

void	init_for_textures(t_data *d)
{
	d->ca = d->pa - d->ra;
	reset_pi(&d->ca);
	d->dist = d->dist * cos(d->ca);
	d->lineh = (d->squaresize * HEIGHT) / d->dist;
	d->ty_step = 32.0 / d->lineh;
	d->ty_off = 0;
}

void	checks_for_textures(t_data *d)
{
	if (d->lineh > HEIGHT)
	{
		d->ty_off = (d->lineh - HEIGHT) / 2.0;
		d->lineh = HEIGHT;
	}
	d->lineo = (HEIGHT / 2) - d->lineh / 2;
	d->ty = d->ty_off * d->ty_step;
	if (d->vertical)
	{
		d->tx = (int)(d->ry / 2.0) % 32;
		if (d->ra > 90 && d->ra < 270)
			d->tx = 31 - d->tx;
	}
	else
	{
		d->tx = (int)(d->rx / 2.0) % 32;
		if (d->ra > 180)
			d->tx = 31 - d->tx;
	}
}

void	check_wall_hit(t_data *d)
{
	d->vertical = 1;
	d->north = 1;
	d->east = 1;
	if (d->disv < d->dish)
	{
		if (d->vx < d->px)
			d->east = 0;
		d->rx = d->vx;
		d->ry = d->vy;
		d->dist = d->disv;
	}
	if (d->dish < d->disv)
	{
		if (d->hy < d->py)
			d->north = 0;
		d->vertical = 0;
		d->rx = d->hx;
		d->ry = d->hy;
		d->dist = d->dish;
	}
}
