/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:35:12 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/17 02:35:49 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init(int fd)
{
	t_map.keys.w = 0;
	t_map.keys.s = 0;
	t_map.keys.d = 0;
	t_map.keys.a = 0;
	g_game.dirx = 0;
	g_game.diry = 0;
	g_game.move_speed = 0.08;
	g_game.planex = 0;
	g_game.planey = 0;
	g_game.rot_speed = 0.04;
	g_game.posx = 0;
	g_game.posy = 0;
	get_columns(fd);
}
