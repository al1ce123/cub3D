/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:06:34 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/17 14:34:15 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define PI 3.1415
# define P2 1.5707
# define P3 4.7121
# define DR 0.0174533
# define WIDTH 1200
# define HEIGHT 600

typedef struct s_textures
{
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	mlx_image_t	*no_img;
	mlx_image_t	*so_img;
	mlx_image_t	*ea_img;
	mlx_image_t	*we_img;
	mlx_image_t	*do_img;
	mlx_image_t	*torch;
	mlx_image_t	*torch1;
	mlx_image_t	*torch2;
	mlx_image_t	*torch3;
	mlx_image_t	*torch4;
}				t_textures;

typedef struct s_data
{
	mlx_t		*mlx;
	t_textures	*t;
	mlx_image_t	*world;
	char		*ccolor;
	char		*fcolor;
	char		*map;
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pa;
	int			mapwidth;
	int			mapheight;
	int			squaresize;
	int			rf;
	int			gf;
	int			bf;
	int			tf;
	int			rc;
	int			gc;
	int			bc;
	int			tc;
	int			vertical;
	int			north;
	int			east;
	int			r;
	int			mx;
	int			my;
	int			mp;
	int			dof;
	float		rx;
	float		ry;
	float		ra;
	float		ca;
	float		xo;
	float		yo;
	float		dist;
	float		dish;
	float		disv;
	float		hx;
	float		hy;
	float		atan;
	float		ntan;
	float		vx;
	float		vy;
	int			cpt;
	float		lineh;
	float		ty_step;
	float		ty_off;
	float		lineo;
	float		ty;
	float		tx;
	int			door;
	double		time;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			offset;
	int			pos;
	int			x_start;
	int			y_start;
	int			pos_start;
	int			pos_end;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

void			init_txt_test(t_data *d);
int				check_colors(char **tab);
char			*get_color(char **tab, char *cmp);
void			freetab(char **tab);
void			err_manager(int err, char **tab);
void			cmp_path(char *ln, int *enu);
int				get_nline(char *fl);
int				is_map(char *ln);
int				get_height(char **tab);
int				counter(char **map);
char			**nfile(char *fl);
int				get_rgb(char *s, int k);
int				map_w(char **tab);
int				map_h(char **tab);
int				is_eol(char *line, int iter);
void			check_cub(int ac, char *fl);
void			init_cub(t_data *cub, char *fl);
char			**nfile(char *fl);
char			**nmap(char **tab);
int				map_leaks(char **map);
int				scan_map(char **map);
int				check_start(char **map);
void			free_data(t_data *cub, int i);
void			move_player(void *param);
void			draw_map(t_data *d);
void			init_ceil_and_floor_color(t_data *d);
void			init_data(t_data *d);
void			check_horizontal_sub1(t_data *d);
void			check_horizontal_sub2(t_data *d);
void			check_horizontal_lines(t_data *d);
void			draw_rays(t_data *d);
void			check_vertical_sub1(t_data *d);
void			check_vertical_sub2(t_data *d);
void			check_vertical_lines(t_data *d);
void			check_right_texture(t_data *d);
void			draw_door_texture(t_data *d);
void			draw_north_texture(t_data *d);
void			draw_south_texture(t_data *d);
void			draw_east_texture(t_data *d);
void			draw_west_texture(t_data *d);
void			draw_ceil_and_floor(t_data *d);
void			draw_rays_init(t_data *d);
void			draw_rays_init2(t_data *d);
void			init_for_textures(t_data *d);
void			checks_for_textures(t_data *d);
void			check_wall_hit(t_data *d);
void			move_forward(t_data *d);
void			move_backwards(t_data *d);
void			move_left(t_data *d);
void			move_right(t_data *d);
void			change_player_direction(t_data *d);
void			draw_player(t_data *d);
void			draw_minimap(t_data *d);
void			draw_torch(t_data *d);
void			draw_torch1(t_data *d);
void			draw_torch2(t_data *d);
void			draw_torch3(t_data *d);
void			draw_torch4(t_data *d);
void			draw_sprite(t_data *d);
int32_t			get_rgba(int r, int g, int b, int a);
void			find_player_px_and_py(t_data *d);
void			find_player_x_and_y(t_data *d, int *coord_x, int *coord_y);
float			find_player_angle(char *map);
void			reset_pi(float *angle);
void			error(t_data *d, int i);
void			draw_line_ceil_check(t_point *pc1, t_point *pc2, t_data *d);
void			draw_line_ceil(t_point *pc1, t_point *pc2, t_data *d);
void			draw_line_floor_check(t_point *pf1, t_point *pf2, t_data *d);
void			draw_line_floor(t_point *pf1, t_point *pf2, t_data *d);
float			dist(float ax, float ay, float bx, float by);
void			open_doors(t_data *d);
void			init_texture(t_data *d);
void			init_texture1(t_data *d);
void			init_texture2(t_data *d);
void			init_texture3(t_data *d);
void			init_texture4(t_data *d);
void			draw_minimap(t_data *d);
void			init_minimap(t_data *d);
void			check_minimap(t_data *d);
void			draw_empty(t_data *d);
void			draw_wall(t_data *d);
void			draw_player(t_data *d);

#endif