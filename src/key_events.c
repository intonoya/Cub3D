/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:20:20 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 04:25:18 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_mlx_mouse_pressed(int button, int x, int y, t_game *mlx)
{
	(void)mlx;
	(void)x;
	(void)y;
	if (button == 1)
	{
		t_map.keys.left = 1;
	}
	if (button == 2)
	{
		t_map.keys.right = 1;
	}
	return (0);
}

int	ft_mlx_mouse_released(int button, int x, int y, t_game *mlx)
{
	(void)mlx;
	(void)x;
	(void)y;
	if (button == 1)
	{
		t_map.keys.left = 0;
	}
	if (button == 2)
	{
		t_map.keys.right = 0;
	}
	return (0);
}

int	ft_mlx_pressed(int keycode)
{
	if (keycode == 53)
		ft_exit("Game over :(");
	else if (keycode == 13)
		t_map.keys.w = 1;
	else if (keycode == 1)
		t_map.keys.s = 1;
	else if (keycode == 0)
		t_map.keys.a = 1;
	else if (keycode == 2)
		t_map.keys.d = 1;
	else if (keycode == 123)
		t_map.keys.left = 1;
	else if (keycode == 124)
		t_map.keys.right = 1;
	return (0);
}

int	ft_mlx_released(int keycode)
{
	if (keycode == 13)
		t_map.keys.w = 0;
	else if (keycode == 1)
		t_map.keys.s = 0;
	else if (keycode == 0)
		t_map.keys.a = 0;
	else if (keycode == 2)
		t_map.keys.d = 0;
	else if (keycode == 123)
		t_map.keys.left = 0;
	else if (keycode == 124)
		t_map.keys.right = 0;
	else if (keycode == 123)
		t_map.keys.left = 0;
	else if (keycode == 124)
		t_map.keys.right = 0;
	return (0);
}
