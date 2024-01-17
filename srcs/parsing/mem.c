/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:24:59 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/17 14:53:10 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	del_cub(t_data *d)
{
	if (d->map)
		free(d->map);
	if (d->fcolor)
		free(d->fcolor);
	if (d->ccolor)
		free(d->ccolor);
	if (d->t->no_path)
		free(d->t->no_path);
	if (d->t->ea_path)
		free(d->t->ea_path);
	if (d->t->we_path)
		free(d->t->we_path);
	if (d->t->so_path)
		free(d->t->so_path);
}

void	del_img(t_data *d, int i)
{
	if (i > 2)
		mlx_delete_image(d->mlx, d->world);
	if (i > 3)
		mlx_delete_image(d->mlx, d->t->do_img);
	if (i > 4)
		mlx_delete_image(d->mlx, d->t->no_img);
	if (i > 5)
		mlx_delete_image(d->mlx, d->t->so_img);
	if (i > 6)
		mlx_delete_image(d->mlx, d->t->torch);
	if (i > 7)
		mlx_delete_image(d->mlx, d->t->torch1);
	if (i > 8)
		mlx_delete_image(d->mlx, d->t->we_img);
	if (i > 9)
		mlx_delete_image(d->mlx, d->t->torch2);
	if (i > 10)
		mlx_delete_image(d->mlx, d->t->torch3);
	if (i > 11)
		mlx_delete_image(d->mlx, d->t->ea_img);
	if (i > 12)
		mlx_delete_image(d->mlx, d->t->torch4);
}

void	free_data(t_data *d, int i)
{
	if (i > 0)
		del_cub(d);
	del_img(d, i);
	if (i > 1)
		mlx_terminate(d->mlx);
	free(d->t);
}
