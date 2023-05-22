/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:26:39 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 05:31:55 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1
# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000
# define TEXTURE_SIZE 64
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h" 
# include "../libft/libft.h"
# include <stdbool.h>

//for img:

typedef struct s_img
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

//for gnl:

typedef struct s_line
{
	char	*line;
	char	*buff;
	char	*tmp;
	char	*ptr;
}				t_line;

//for keys:

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}				t_keys;

//for map:

struct s_map
{
	t_img		data;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_keys		keys;
	int			f_colour[3];
	int			c_colour[3];
	int			rows_tmp;
	int			rows;
	int			cols;
	char		**tmp_map;
	char		**matrix;
}				t_map;

//for cub:

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			mapx;
	int			mapy;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		move_speed;
	double		rot_speed;
	int			step_x;
	int			step_y;
	int			s_count;
	char		player_view;
}				t_game;

struct	s_vars
{
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		color;
	double	buffer[WIN_WIDTH];
	double	wall_x;
	double	step;
	double	tex_pos;
}		vars;

t_game 			g_game;

//for map:

int		check_map_name(char *string, char *extension);
void    check_invalid_characters_helper(int i, int j);
int		check_invalid_characters(void);
void	first_and_last_row(char *str);
void	col_border(char *s);

//for extension:

int 	file_exists(char *filename);
int 	check_extension(char *fn, char *fm);
int 	is_space(char *str);
int		check_colours(void);

//ft_mlx_functions:

int		ft_mlx_pressed(int keycode);
int		ft_mlx_released(int keycode);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

//for matrix:

void	matrix(void);
void	minus_check(int i, int j);
void	allocate_matrix(int rows, int cols);
char    **free_matrix(char **map);
void	check_borders(void);

//for map:

char	*remove_empty_lines(int fd);
void	tmp_map(int fd);
void	r_and_c(void);
void	map_setting(int fd);
void	get_columns(int fd);


void	ft_clear(void);
int		ft_exit(char *str);
void	ft_free(void);
int		start(void);

//keys:

void	right_key(double old_dirx, double old_planex);
void	read_arrow_keys(void);
void	a_d_keys(void);
void	read_keys(void);

//for position:

int		check_start_position(char symbol, int *is_there);
void	set_player_position(int x, int y);
void	set_player_dir_plane_helper(char **map);
void	set_player_dir_plane(char **map);

//for gnl:

size_t	ft_gnl_strlen(char *str);
char	*ft_gnl_strjoin(char *s1, char *s2);
char 	*ft_gnl_strchr(char *s, int c);
int		get_next_line(int fd, char **line);

void	init(int fd);

//parsing:

void	ft_colour(char *line, char mode);
char	*texture_path(char *line);
void	ft_texture(char *line);
void	parsing(int fd);

//for mlx:

void	set_mlx_images(void);
void	set_mlx_addresses(void);
int		rgb(int *colors);
int		get_color(t_img *data, int x, int y);

//raycasting:

void	raycasting_vars(int x);
void	ft_ray_directions(void);
void	ft_wall_hit(void);
void	ft_init_vars(void);
void	ft_draw(int *x);
void	ft_raycasting(void);


#endif