/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:32:01 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:41:11 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_mlx_start(void)
{
	g_game.mlx = mlx_init();
	set_mlx_images();
	set_mlx_addresses();
	g_game.mlx_win = mlx_new_window(g_game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, t_map.data.img, 0, 0);
	mlx_hook(g_game.mlx_win, 2, 1L << 0, ft_mlx_pressed, &g_game.mlx);
	mlx_hook(g_game.mlx_win, 3, 1L << 1, ft_mlx_released, &g_game.mlx);
	mlx_hook(g_game.mlx_win, 17, 1L << 17, ft_exit, NULL);
	mlx_loop_hook(g_game.mlx, start, &g_game);
	mlx_loop(g_game.mlx);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_exit("Error: Invalid parameter!");
		if (!(check_extension(argv[1], ".cub")))
			ft_exit("Error: Invalid file!");
		init(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		parsing(fd);
		ft_mlx_start();
		ft_free();
	}
	return (0);
}
