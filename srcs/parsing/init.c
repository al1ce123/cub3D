/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:26:01 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/17 14:40:39 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*get_path(char **tab, char *cmp1, char *cmp2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 2;
	k = 0;
	if (!tab)
		return (NULL);
	while (tab[i] && ft_strncmp(tab[i], cmp1, 3) && ft_strncmp(tab[i], cmp2, 2))
		i++;
	if (!tab[i])
		return (NULL);
	if (ft_strncmp(tab[i], cmp1, 3) == 0)
		j++;
	while (tab[i][j] && tab[i][j] == ' ')
		j++;
	k = j;
	while (tab[i][j] && tab[i][j] != '\n' && tab[i][j] != ' ')
		j++;
	return (ft_substr(tab[i], k, (j - k)));
}

char	*get_color(char **tab, char *cmp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 2;
	k = 0;
	if (!tab)
		return (NULL);
	while (tab[i] && ft_strncmp(tab[i], cmp, 2))
		i++;
	if (!tab[i])
		return (NULL);
	while (tab[i][j] == ' ')
		j++;
	k = j;
	while (tab[i][j] && (ft_isdigit(tab[i][j]) || tab[i][j] == ','))
		j++;
	return (ft_substr(tab[i], k, (j - k)));
}

char	*get_map(t_data *d, char **tab)
{
	char	*map;
	int		i;
	int		j;
	int		k;

	map = ft_calloc(sizeof(char), (d->mapheight * d->mapwidth) + 1);
	if (!map)
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	while (tab[++i])
	{
		j = -1;
		while (++j < d->mapwidth)
		{
			if (!is_eol(tab[i], j) && tab[i][j] && tab[i][j] != 0
				&& tab[i][j] != ' ' && tab[i][j] != '\n')
				map[k++] = tab[i][j];
			else
				map[k++] = '1';
		}
	}
	return (map);
}

int	get_cub(t_data *d, char **ftab, char **tmp)
{
	d->squaresize = 64;
	d->mapheight = map_h(tmp);
	d->mapwidth = map_w(tmp);
	d->map = get_map(d, tmp);
	if (!d->map)
		return (1);
	d->ccolor = get_color(ftab, "C ");
	if (!d->ccolor)
		return (1);
	d->fcolor = get_color(ftab, "F ");
	if (!d->fcolor)
		return (1);
	d->t->no_path = get_path(ftab, "NO ", "N ");
	if (!d->t->no_path)
		return (1);
	d->t->so_path = get_path(ftab, "SO ", "S ");
	if (!d->t->so_path)
		return (1);
	d->t->we_path = get_path(ftab, "WE ", "W ");
	if (!d->t->we_path)
		return (1);
	d->t->ea_path = get_path(ftab, "EA ", "E ");
	if (!d->t->ea_path)
		return (1);
	return (0);
}

void	init_cub(t_data *d, char *fl)
{
	char	**ftab;
	char	**tmp;

	ftab = nfile(fl);
	if (!ftab)
		error(d, 0);
	tmp = nmap(ftab);
	if (!tmp)
	{
		free(ftab);
		error(d, 0);
	}
	d->t = malloc(sizeof(t_textures));
	if (!d->t)
	{
		freetab(ftab);
		freetab(tmp);
		error(d, 0);
	}
	if (get_cub(d, ftab, tmp))
		error(d, 1);
	freetab(ftab);
	freetab(tmp);
	return ;
}
