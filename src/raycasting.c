/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 04:55:10 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:09:37 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_ray_directions(void)
{
	if (g_game.ray_dir_x < 0)
	{
		g_game.step_x = -1;
		g_game.side_dist_x = (g_game.posx - g_game.mapx) * g_game.delta_dist_x;
	}
	else
	{
		g_game.step_x = 1;
		g_game.side_dist_x = (g_game.mapx - g_game.posx + 1.0)
			* g_game.delta_dist_x;
	}
	if (g_game.ray_dir_y < 0)
	{
		g_game.step_y = -1;
		g_game.side_dist_y = (g_game.posy - g_game.mapy) * g_game.delta_dist_y;
	}
	else
	{
		g_game.step_y = 1;
		g_game.side_dist_y = (g_game.mapy - g_game.posy + 1.0)
			* g_game.delta_dist_y;
	}
}

void	ft_wall_hit(void)
{
	while (vars.hit == 0)
	{
		if (g_game.side_dist_x < g_game.side_dist_y)
		{
			g_game.side_dist_x += g_game.delta_dist_x;
			g_game.mapx += g_game.step_x;
			vars.side = 0;
		}
		else
		{
			g_game.side_dist_y += g_game.delta_dist_y;
			g_game.mapy += g_game.step_y;
			vars.side = 1;
		}
		if (t_map.matrix[g_game.mapx][g_game.mapy] == '1')
			vars.hit = 1;
	}
	if (vars.side == 0)
		g_game.perp_wall_dist = (g_game.mapx - g_game.posx + (1 - g_game.step_x)
				/ 2) / g_game.ray_dir_x;
	else
		g_game.perp_wall_dist = (g_game.mapy - g_game.posy + (1 - g_game.step_y)
				/ 2) / g_game.ray_dir_y;
}

void	ft_init_vars(void)
{
	vars.line_height = (int)(WIN_HEIGHT / g_game.perp_wall_dist);
	vars.draw_start = -vars.line_height / 2 + WIN_HEIGHT / 2;
	vars.draw_end = vars.line_height / 2 + WIN_HEIGHT / 2;
	if (vars.draw_start < 0)
		vars.draw_start = 0;
	if (vars.draw_end >= WIN_HEIGHT)
		vars.draw_end = WIN_HEIGHT - 1;
	if (vars.side == 0)
		vars.wall_x = g_game.posy + g_game.perp_wall_dist * g_game.ray_dir_y;
	else
		vars.wall_x = g_game.posx + g_game.perp_wall_dist * g_game.ray_dir_x;
	vars.wall_x -= floor((vars.wall_x));
	vars.tex_x = (int)(vars.wall_x * (double)(TEXTURE_SIZE));
	if (vars.side == 0 && g_game.ray_dir_x > 0)
		vars.tex_x = TEXTURE_SIZE - vars.tex_x - 1;
	if (vars.side == 1 && g_game.ray_dir_y < 0)
		vars.tex_x = TEXTURE_SIZE - vars.tex_x - 1;
	vars.step = 1.0 * TEXTURE_SIZE / vars.line_height;
	vars.tex_pos = (vars.draw_start - WIN_HEIGHT / 2 + vars.line_height
			/ 2) * vars.step;
}

void	ft_draw(int *x)
{
	int	y;

	y = vars.draw_start;
	while (y < vars.draw_end)
	{
		vars.tex_y = (int)vars.tex_pos & (TEXTURE_SIZE - 1);
		vars.tex_pos += vars.step;
		if (vars.side == 0)
		{
			if (g_game.step_x > 0)
				vars.colour = get_colour(&t_map.south, vars.tex_x, vars.tex_y);
			else
				vars.colour = get_colour(&t_map.north, vars.tex_x, vars.tex_y);
		}
		else
		{
			if (g_game.step_y > 0)
				vars.colour = get_colour(&t_map.west, vars.tex_x, vars.tex_y);
			else
				vars.colour = get_colour(&t_map.east, vars.tex_x, vars.tex_y);
		}
		my_mlx_pixel_put(&t_map.data, *x, y, vars.colour);
		y++;
	}
}

void	ft_raycasting(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars.colour = 0;
	while (x < WIN_WIDTH)
	{
		raycasting_vars(x);
		ft_ray_directions();
		ft_wall_hit();
		ft_init_vars();
		y = 0;
		while (y++ < vars.draw_start)
			my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.c_colour));
		ft_draw(&x);
		y = vars.draw_end;
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.f_colour));
			y++;
		}
		vars.buffer[x] = g_game.perp_wall_dist;
		x++;
	}
}
