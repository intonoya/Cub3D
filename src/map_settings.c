/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:17:48 by intonoya          #+#    #+#             */
/*   Updated: 2023/06/12 20:51:39 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*remove_empty_lines(int fd)
{
	int		result;
	char	*line;

	result = get_next_line(fd, &line);
	while (result > 0)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			result = get_next_line(fd, &line);
			continue ;
		}
		else
			break ;
	}
	return (line);
}

void	puchurik_funkcia(char **result, char *line, char **a)
{
	*a = ft_strjoin(line, "\n");
	*result = ft_strjoin(*result, *a);
	free(*a);
}

void	tmp_map(int fd)
{
	int		r;
	char	*result;
	char	*tmp;
	char	*line;
	char	*a;

	a = remove_empty_lines(fd);
	result = NULL;
	line = ft_strjoin(a, "\n");
	free(a);
	result = line;
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		a = ft_strjoin(line, "\n");
		tmp = ft_strjoin(result, a);
		wtf(&a, &result);
		result = tmp;
		free(line);
		r = get_next_line(fd, &line);
	}
	if (line)
		puchurik_funkcia(&result, line, &a);
	t_map.tmp_map = ft_split(result, '\n');
	wtf_2(&line, &result, &tmp);
}

void	r_and_c(void)
{
	int	i;

	i = 0;
	while (t_map.tmp_map[i] != 0)
		i++;
	t_map.rows = i;
}

void	map_setting(int fd)
{
	tmp_map(fd);
	close(fd);
	r_and_c();
	matrix();
	check_borders();
}
