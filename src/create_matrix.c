/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:21:07 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/17 04:59:58 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_columns(int fd)
{
	char		*line;
	int			column;
	int			ret;
	int			max_column;

	max_column = 0;
	line = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		free(line);
		column = ft_strlen(line);
		if (column > max_column)
			max_column = column;
		if (!ret)
			break ;
	}
	t_map.cols = max_column;
	close(fd);
}

void	allocate_matrix(int rows, int cols)
{
	int	i;

	i = 0;
	t_map.matrix = (char **)malloc(sizeof(char *) * (rows));
	if (!t_map.matrix)
		ft_exit("Error: Malloc error!");
	while (i < rows)
		t_map.matrix[i++] = (char *)malloc(sizeof(char) * (cols));
}

void	matrix_helper(int i, size_t j)
{
	while (j < (size_t)t_map.cols)
	{
		t_map.matrix[i][j] = '-';
		j++;
	}
	t_map.matrix[i][j] = '\0';
}

void	matrix(void)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	allocate_matrix(t_map.rows, t_map.cols);
	while (i < t_map.rows)
	{
		j = 0;
		while (j < ft_strlen(t_map.tmp_map[i]))
		{
			if (t_map.tmp_map[i][j] == ' ')
				t_map.matrix[i][j] = '-';
			else
				t_map.matrix[i][j] = t_map.tmp_map[i][j];
			j++;
		}
		matrix_helper(i, j);
		i++;
	}
	free_matrix(t_map.tmp_map);
}

void	check_borders(void)
{
	int	i;
	int	j;

	i = 0;
	check_invalid_characters();
	while (i < t_map.rows)
	{
		j = 0;
		if (i == 0 || i == t_map.rows - 1)
			first_and_last_row(t_map.matrix[i]);
		else
			col_border(t_map.matrix[i]);
		while (j < t_map.cols)
		{
			if (t_map.matrix[i][j] == '-')
				minus_check(i, j);
			j++;
		}
		i++;
	}
}
