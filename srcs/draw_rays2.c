/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:45 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:58 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_vertical_sub1(t_data *d)
{
	draw_rays_init2(d);
	if (d->ra > P2 && d->ra < P3)
	{
		d->rx = (((int) d->px >> 6) << 6) - 0.001;
		d->ry = (d->px - d->rx) * d->ntan + d->py;
		d->xo = -d->squaresize;
		d->yo = -d->xo * d->ntan;
	}
	if (d->ra < P2 || d->ra > P3)
	{
		d->rx = (((int) d->px >> 6) << 6) + d->squaresize;
		d->ry = (d->px - d->rx) * d->ntan + d->py;
		d->xo = d->squaresize;
		d->yo = -d->xo * d->ntan;
	}
	if (d->ra == 0 || d->ra == PI)
	{
		d->rx = d->px;
		d->ry = d->py;
		d->dof = d->mapwidth;
	}
}

void	check_vertical_sub2(t_data *d)
{
	while (d->dof < d->mapwidth)
	{
		d->mx = (int)(d->rx) >> 6;
		d->my = (int)(d->ry) >> 6;
		d->mp = d->my * d->mapwidth + d->mx;
		if ((d->mp > 0 && d->mp < d->mapwidth * d->mapheight
				&& d->map[d->mp] == '1')
			|| (d->mp > 0 && d->mp < d->mapwidth * d->mapheight
				&& d->map[d->mp] == '4'))
		{
			d->vx = d->rx;
			d->vy = d->ry;
			d->disv = dist(d->px, d->py, d->vx, d->vy);
			d->dof = d->mapwidth;
		}
		else
		{
			d->rx += d->xo;
			d->ry += d->yo;
			d->dof += 1;
		}
	}
}

void	check_vertical_lines(t_data *d)
{
	check_vertical_sub1(d);
	check_vertical_sub2(d);
}

void	check_right_texture(t_data *d)
{
	if (d->vertical)
	{
		if (d->east)
			draw_east_texture(d);
		else
			draw_west_texture(d);
	}
	else
	{
		if (d->north)
		{
			if (d->door)
				draw_door_texture(d);
			else
				draw_north_texture(d);
		}
		else
		{
			if (d->door)
				draw_door_texture(d);
			else
				draw_south_texture(d);
		}
	}
}

void	draw_ceil_and_floor(t_data *d)
{
	int		i;
	t_point	pc1;
	t_point	pc2;
	t_point	pf1;
	t_point	pf2;

	i = 0;
	while (i < WIDTH / 120)
	{
		pc1.x = d->r + i + d->cpt;
		pc1.y = 0;
		pc2.x = d->r + i + d->cpt;
		pc2.y = (int)d->lineo;
		pf1.x = d->r + i + d->cpt;
		pf1.y = (int)d->lineh + (int)d->lineo;
		pf2.x = d->r + i + d->cpt;
		pf2.y = HEIGHT;
		draw_line_ceil(&pc1, &pc2, d);
		draw_line_floor(&pf1, &pf2, d);
		i++;
	}
}
