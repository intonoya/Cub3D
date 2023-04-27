/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:17:00 by intonoya          #+#    #+#             */
/*   Updated: 2023/04/27 22:27:38 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    check_invalid_characters1(int i, int j)
{
    if (t_map.matrix[i][j] != 'N' && t_map.matrix[i][j] != 'S' &&
		t_map.matrix[i][j] != 'W' && t_map.matrix[i][j] != 'E' &&
		t_map.matrix[i][j] != '0' && t_map.matrix[i][j] != '1' &&
		t_map.matrix[i][j] != '-')
	{
		ft_exit("Error: Invalid symbol in map!");
	}
	if (t_map.matrix[i][j] == 'N' || t_map.matrix[i][j] == 'S' ||
		t_map.matrix[i][j] == 'W' || t_map.matrix[i][j] == 'E')
	{
		set_player_pos(j, i);
		set_player_dir_plane(t_map.matrix);
	}
}

int	check_invalid_characters2(void)
{
	int			i;
	size_t		j;
	int			current;

	current = 0;
	i = 1;
	while (i < t_map.rows)
	{
		j = 1;
		while (j < ft_strlen(t_map.matrix[i]))
		{
			//check_on_one_start_position(t_map.matrix[i][j], &current);
			check_invalid_characters1(i, j);
			j++;
		}
		i++;
	}
	if (current == 0)
		ft_exit("Error: Missing start position!");
	return (1);
}