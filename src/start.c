/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:55:26 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:47:28 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	start(void)
{
	read_keys();
	ft_clear();
	ft_raycasting();
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, t_map.data.img, 0, 0);
	mlx_do_sync(g_game.mlx);
	return (0);
}
