/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:39:25 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/22 06:53:00 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

size_t	ft_gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(sizeof(char) * (ft_gnl_strlen(s1)
				+ ft_gnl_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
			join[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			join[j++] = s2[i++];
	join[j] = '\0';
	free(s1);
	return (join);
}

char	*ft_gnl_strchr(char *s, int c)
{
	if (c == '\0')
		return (&((char *)s)[ft_gnl_strlen(s)]);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
