/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:06:22 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:58 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_horizontal_sub1(t_data *d)
{
	draw_rays_init(d);
	if (d->ra > PI)
	{
		d->ry = (((int) d->py >> 6) << 6) - 0.001;
		d->rx = (d->py - d->ry) * d->atan + d->px;
		d->yo = -d->squaresize;
		d->xo = -d->yo * d->atan;
	}
	if (d->ra < PI)
	{
		d->ry = (((int) d->py >> 6) << 6) + d->squaresize;
		d->rx = (d->py - d->ry) * d->atan + d->px;
		d->yo = d->squaresize;
		d->xo = -d->yo * d->atan;
	}
	if (d->ra == 0 || d->ra == PI)
	{
		d->rx = d->px;
		d->ry = d->py;
		d->dof = d->mapheight;
	}
}

void	check_horizontal_sub2(t_data *d)
{
	while (d->dof < d->mapheight)
	{
		d->mx = (int)(d->rx) >> 6;
		d->my = (int)(d->ry) >> 6;
		d->mp = d->my * d->mapwidth + d->mx;
		if ((d->mp > 0 && d->mp < d->mapwidth * d->mapheight
				&& d->map[d->mp] == '1')
			|| (d->mp > 0 && d->mp < d->mapwidth * d->mapheight
				&& d->map[d->mp] == '4'))
		{
			if (d->mp > 0 && d->mp < d->mapwidth * d->mapheight
				&& d->map[d->mp] == '4')
				d->door = 1;
			d->hx = d->rx;
			d->hy = d->ry;
			d->dish = dist(d->px, d->py, d->hx, d->hy);
			d->dof = d->mapheight;
		}
		else
		{
			d->rx += d->xo;
			d->ry += d->yo;
			d->dof += 1;
		}
	}
}

void	check_horizontal_lines(t_data *d)
{
	check_horizontal_sub1(d);
	check_horizontal_sub2(d);
}

void	draw_rays(t_data *d)
{
	d->cpt = 0;
	d->ra = d->pa - DR * 30;
	d->r = 0;
	reset_pi(&d->ra);
	while (d->r < 120)
	{
		check_horizontal_lines(d);
		check_vertical_lines(d);
		check_wall_hit(d);
		init_for_textures(d);
		checks_for_textures(d);
		check_right_texture(d);
		draw_ceil_and_floor(d);
		d->cpt += (WIDTH / 120 - 1);
		d->ra += DR * 0.5;
		reset_pi(&d->ra);
		d->door = 0;
		d->r++;
	}
}
