/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:13:10 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/17 02:46:00 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_colour(char *line, char mode)
{
	int		i;
	int		len;
	char	**colours;

	i = 0;
	len = 0;
	while (*line == ' ')
		line++;
	colours = ft_split(line, ',');
	while (colours[i++])
		len++;
	if (len != 3)
		ft_exit("Error: Wrong colour numbers!");
	i = 0;
	while (i < 3)
	{
		if (mode == 'F')
			t_map.f_colour[i] = ft_atoi(colours[i]);
		else if (mode == 'C')
			t_map.c_colour[i] = ft_atoi(colours[i]);
		i++;
	}
	if (!check_colours())
		ft_exit("Error: Wrong colour numbers!");
	free_matrix(colours);
}

char	*texture_path(char *line)
{
	char	*path;
	int		fd;

	while (*line == ' ')
		line++;
	path = ft_strdup(line);
	if (!(check_map_name(path, ".xpm")))
		ft_exit ("Error: File extension error");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit ("File doesn't exist");
	else
		close (fd);
	return (path);
}

void	ft_texture(char *line)
{
	while (*line == ' ')
	{
		t_map.rows_tmp++;
		line++;
	}
	if (line[0] == 'N' && line[1] == 'O')
	{
		t_map.north.path = texture_path(line + 2);
	}
	else if (line[0] == 'S' && line[1] == 'O')
		t_map.south.path = texture_path(line + 2);
	else if (line[0] == 'W' && line[1] == 'E')
		t_map.west.path = texture_path(line + 2);
	else if (line[0] == 'E' && line[1] == 'A')
		t_map.east.path = texture_path(line + 2);
	else if (line[0] == 'F')
		ft_colour(line + 1, 'F');
	else if (line[0] == 'C')
		ft_colour(line + 1, 'C');
}

void	parsing(int fd)
{
	int		i;
	char	*line;

	i = 0;
	t_map.rows_tmp = 0;
	while (i < 6 && get_next_line(fd, &line))
	{
		t_map.rows_tmp++;
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		else
			ft_texture(line);
		free(line);
		i++;
	}
	if (t_map.east.path == NULL || t_map.west.path == NULL
		|| t_map.north.path == NULL || t_map.south.path == NULL)
		ft_exit("Error: missing texture");
	map_setting(fd);
}
