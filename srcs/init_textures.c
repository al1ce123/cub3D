/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:29:54 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/17 14:27:52 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_texture(t_data *d)
{
	init_texture1(d);
	init_texture2(d);
	init_texture3(d);
	init_texture4(d);
}

void	init_texture1(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./textures/eagle.png");
	if (!temp)
		error(d, 3);
	d->t->do_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->do_img)
		error(d, 3);
	mlx_delete_texture(temp);
	temp = mlx_load_png(d->t->no_path);
	if (!temp)
		error(d, 4);
	d->t->no_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->no_img)
		error(d, 4);
	mlx_delete_texture(temp);
	temp = mlx_load_png(d->t->so_path);
	if (!temp)
		error(d, 5);
	d->t->so_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->so_img)
		error(d, 5);
	mlx_delete_texture(temp);
}

void	init_texture2(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./textures/torch.png");
	if (!temp)
		error(d, 6);
	d->t->torch = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch)
		error(d, 6);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./textures/torch1.png");
	if (!temp)
		error(d, 7);
	d->t->torch1 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch1)
		error(d, 7);
	mlx_delete_texture(temp);
	temp = mlx_load_png(d->t->we_path);
	if (!temp)
		error(d, 8);
	d->t->we_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->we_img)
		error(d, 8);
	mlx_delete_texture(temp);
}

void	init_texture3(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./textures/torch2.png");
	if (!temp)
		error(d, 9);
	d->t->torch2 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch2)
		error(d, 9);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./textures/torch3.png");
	if (!temp)
		error(d, 10);
	d->t->torch3 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch3)
		error(d, 10);
	mlx_delete_texture(temp);
}

void	init_texture4(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(d->t->ea_path);
	if (!temp)
		error(d, 11);
	d->t->ea_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->ea_img)
		error(d, 11);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./textures/torch4.png");
	if (!temp)
		error(d, 12);
	d->t->torch4 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch4)
		error(d, 12);
	mlx_delete_texture(temp);
}
