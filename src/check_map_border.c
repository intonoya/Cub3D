/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:17:00 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:29:44 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	first_and_last_row(char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != '-')
			ft_exit("Error: Open border!");
		str++;
	}
}

void	col_border(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = t_map.cols - 1;
	while (s[i] == '-' && s[i] != '\0')
		i++;
	while (s[j] == '-' && j >= 0)
		j--;
	if (s[i] != '1' || s[j] != '1')
	{
		printf("%d %d\n", i, j);
		ft_exit("Error: Open border?");
	}
}

void	check_invalid_characters_helper(int i, int j)
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
		set_player_position(j, i);
		set_player_dir_plane(t_map.matrix);
	}
}

int	check_invalid_characters(void)
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
			check_start_position(t_map.matrix[i][j], &current);
			check_invalid_characters_helper(i, j);
			j++;
		}
		i++;
	}
	if (current == 0)
		ft_exit("Error: Missing start position!");
	return (1);
}
