/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:24:16 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/17 02:30:47 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_player_position(int x, int y)
{
	g_game.player_view = t_map.matrix[y][x];
	g_game.posy = (double)x + 0.5;
	g_game.posx = (double)y + 0.5;
}

void	set_player_dir_plane_helper(char **map)
{
	if (map[(int)(g_game.posx - 0.5)][(int)(g_game.posy - 0.5)] == 'E')
	{
		g_game.dirx = 0.0;
		g_game.diry = 1.0;
		g_game.planex = 0.66;
		g_game.planey = 0.0;
	}
	else if (map[(int)(g_game.posx - 0.5)][(int)(g_game.posy - 0.5)] == 'W')
	{
		g_game.dirx = 0.0;
		g_game.diry = -1.0;
		g_game.planex = -0.66;
		g_game.planey = 0.0;
	}
}

void	set_player_dir_plane(char **map)
{
	if (map[(int)(g_game.posx - 0.5)][(int)(g_game.posy - 0.5)] == 'N')
	{
		g_game.dirx = -1.0;
		g_game.diry = 0.0;
		g_game.planex = 0.0;
		g_game.planey = 0.66;
	}
	else if (map[(int)(g_game.posx - 0.5)][(int)(g_game.posy - 0.5)] == 'S')
	{
		g_game.dirx = 1.0;
		g_game.diry = 0.0;
		g_game.planex = 0.0;
		g_game.planey = -0.66;
	}
	set_player_dir_plane_helper(map);
	map[(int)(g_game.posx - 0.5)][(int)(g_game.posy - 0.5)] = '0';
}

int	check_start_position(char symbol, int *is_there)
{
	if (symbol == 'N' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'N' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	if (symbol == 'W' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'W' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	if (symbol == 'E' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'E' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	if (symbol == 'S' && (*is_there) == 0)
		(*is_there) = 1;
	else if (symbol == 'S' && (*is_there) != 0)
		ft_exit("Error: More than one start position!");
	return (1);
}
