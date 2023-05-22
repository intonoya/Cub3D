/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:17:00 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:27:46 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_extension(char *fn, char *fm)
{
	int	fn_len;
	int	fm_len;

	if (!(file_exists(fn)))
		return (0);
	fn_len = ft_strlen(fn);
	fm_len = ft_strlen(fm);
	if (!(fm_len == 4) && !(fn_len > 4))
		return (0);
	return (*(fn + fn_len - 1) == *(fm + fm_len - 1)
		&& *(fn + fn_len - 2) == *(fm + fm_len - 2)
		&& *(fn + fn_len - 3) == *(fm + fm_len - 3)
		&& *(fn + fn_len - 4) == *(fm + fm_len - 4));
}

int	check_map_name(char *string, char *extension)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(extension);
	while (string[i])
		i++;
	while (len--)
		i--;
	if (string[i] == '.')
		if (ft_strncmp((string + i - 1), extension, ft_strlen(extension)))
			return (1);
	return (0);
}

int	check_colours(void)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (t_map.f_colour[i] < 0 || t_map.f_colour[i] > 255)
			return (0);
		if (t_map.c_colour[i] < 0 || t_map.c_colour[i] > 255)
			return (0);
		if (t_map.c_colour[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_space(char *str)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}
