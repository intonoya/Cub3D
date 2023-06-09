/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:49:00 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:40:06 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	right_key(double old_dirx, double old_planex)
{
	g_game.dirx = g_game.dirx * cos(-g_game.rot_speed) - g_game.diry
		* sin(-g_game.rot_speed);
	g_game.diry = old_dirx * sin(-g_game.rot_speed) + g_game.diry
		* cos(-g_game.rot_speed);
	g_game.planex = g_game.planex * cos(-g_game.rot_speed) - g_game.planey
		* sin(-g_game.rot_speed);
	g_game.planey = old_planex * sin(-g_game.rot_speed) + g_game.planey
		* cos(-g_game.rot_speed);
}

void	read_arrow_keys(void)
{
	double	old_dirx;
	double	old_planex;

	old_planex = g_game.planex;
	old_dirx = g_game.dirx;
	if (t_map.keys.right)
	{
		right_key(old_dirx, old_planex);
		if (t_map.mouse_hook)
			t_map.keys.right = 0;
	}
	else if (t_map.keys.left)
	{
		g_game.dirx = g_game.dirx * cos(g_game.rot_speed) - g_game.diry
			* sin(g_game.rot_speed);
		g_game.diry = old_dirx * sin(g_game.rot_speed) + g_game.diry
			* cos(g_game.rot_speed);
		g_game.planex = g_game.planex * cos(g_game.rot_speed) - g_game.planey
			* sin(g_game.rot_speed);
		g_game.planey = old_planex * sin(g_game.rot_speed) + g_game.planey
			* cos(g_game.rot_speed);
		if (t_map.mouse_hook)
			t_map.keys.left = 0;
	}
}

void	a_d_keys(void)
{
	if (t_map.keys.d)
	{
		if (t_map.matrix[(int)(g_game.posx + g_game.diry
				* g_game.move_speed)][(int)(g_game.posy)] == '0')
			g_game.posx += g_game.diry * g_game.move_speed;
		if (t_map.matrix[(int)(g_game.posx)][(int)(g_game.posy - g_game.dirx
				* g_game.move_speed)] == '0')
			g_game.posy -= g_game.dirx * g_game.move_speed;
	}
	else if (t_map.keys.a)
	{
		if (t_map.matrix[(int)(g_game.posx - g_game.diry
				* g_game.move_speed)][(int)(g_game.posy)] == '0')
			g_game.posx -= g_game.diry * g_game.move_speed;
		if (t_map.matrix[(int)(g_game.posx)][(int)(g_game.posy + g_game.dirx
				* g_game.move_speed)] == '0')
			g_game.posy += g_game.dirx * g_game.move_speed;
	}
}

void	read_keys(void)
{
	if (t_map.keys.w)
	{
		if (t_map.matrix[(int)((g_game.posx) + g_game.dirx
				* g_game.move_speed)][(int)(g_game.posy)] == '0')
			g_game.posx += g_game.dirx * g_game.move_speed;
		if (t_map.matrix[(int)(g_game.posx)][(int)((g_game.posy) + g_game.diry
				* g_game.move_speed)] == '0')
			(g_game.posy) += g_game.diry * g_game.move_speed;
	}
	else if (t_map.keys.s)
	{
		if (t_map.matrix[(int)(g_game.posx - g_game.dirx
				* g_game.move_speed)][(int)(g_game.posy)] == '0')
			g_game.posx -= g_game.dirx * g_game.move_speed;
		if (t_map.matrix[(int)(g_game.posx)][(int)(g_game.posy - g_game.diry
				* g_game.move_speed)] == '0')
			g_game.posy -= g_game.diry * g_game.move_speed;
	}
	a_d_keys();
	read_arrow_keys();
}
