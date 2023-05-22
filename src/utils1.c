/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:11:44 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:48:49 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

void	ft_clear(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(&t_map.data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	ft_free(void)
{
	free_matrix(t_map.matrix);
	free(g_game.mlx);
	free(g_game.mlx_win);
	free(t_map.data.path);
	free(t_map.data.img);
	free(t_map.data.addr);
	free(t_map.north.path);
	free(t_map.north.img);
	free(t_map.north.addr);
	free(t_map.south.path);
	free(t_map.south.img);
	free(t_map.south.addr);
	free(t_map.west.path);
	free(t_map.west.img);
	free(t_map.west.addr);
	free(t_map.east.path);
	free(t_map.east.img);
	free(t_map.east.addr);
}
