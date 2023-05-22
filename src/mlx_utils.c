/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:50:14 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:45:27 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	rgb(int *colours)
{
	return ((colours[0] << 16) + (colours[1] << 8) + colours[2]);
}

int	get_colour(t_img *data, int x, int y)
{
	return (*(int *)(data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8))));
}

void	set_mlx_images(void)
{
	t_map.data.img = mlx_new_image(g_game.mlx, WIN_WIDTH, WIN_HEIGHT);
	t_map.north.img = mlx_xpm_file_to_image(g_game.mlx, t_map.north.path,
			&t_map.north.width, &t_map.north.height);
	t_map.south.img = mlx_xpm_file_to_image(g_game.mlx, t_map.south.path,
			&t_map.south.width, &t_map.south.height);
	t_map.west.img = mlx_xpm_file_to_image(g_game.mlx, t_map.west.path,
			&t_map.west.width, &t_map.west.height);
	t_map.east.img = mlx_xpm_file_to_image(g_game.mlx, t_map.east.path,
			&t_map.east.width, &t_map.east.height);
}

void	set_mlx_addresses(void)
{
	t_map.data.addr = mlx_get_data_addr(t_map.data.img,
			&t_map.data.bits_per_pixel,
			&t_map.data.line_length, &t_map.data.endian);
	t_map.south.addr = mlx_get_data_addr(t_map.south.img,
			&t_map.south.bits_per_pixel,
			&t_map.south.line_length, &t_map.south.endian);
	t_map.north.addr = mlx_get_data_addr(t_map.north.img,
			&t_map.north.bits_per_pixel,
			&t_map.north.line_length, &t_map.north.endian);
	t_map.west.addr = mlx_get_data_addr(t_map.west.img,
			&t_map.west.bits_per_pixel,
			&t_map.west.line_length, &t_map.west.endian);
	t_map.east.addr = mlx_get_data_addr(t_map.east.img,
			&t_map.east.bits_per_pixel,
			&t_map.east.line_length, &t_map.east.endian);
}
