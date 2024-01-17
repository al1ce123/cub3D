/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:52 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/17 14:27:52 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_door_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineh)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineo,
					get_rgba(d->t->do_img->pixels[pixel + 0],
						d->t->do_img->pixels[pixel + 1],
						d->t->do_img->pixels[pixel + 2],
						d->t->do_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_north_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineh)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineo,
					get_rgba(d->t->no_img->pixels[pixel + 0],
						d->t->no_img->pixels[pixel + 1],
						d->t->no_img->pixels[pixel + 2],
						d->t->no_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_south_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineh)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineo,
					get_rgba(d->t->so_img->pixels[pixel + 0],
						d->t->so_img->pixels[pixel + 1],
						d->t->so_img->pixels[pixel + 2],
						d->t->so_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_east_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineh)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineo,
					get_rgba(d->t->ea_img->pixels[pixel + 0],
						d->t->ea_img->pixels[pixel + 1],
						d->t->ea_img->pixels[pixel + 2],
						d->t->ea_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_west_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineh)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineo,
					get_rgba(d->t->we_img->pixels[pixel + 0],
						d->t->we_img->pixels[pixel + 1],
						d->t->we_img->pixels[pixel + 2],
						d->t->we_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}
