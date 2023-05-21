/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:51:19 by intonoya          #+#    #+#             */
/*   Updated: 2023/05/01 18:52:03 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	minus_check(int i, int j)
{
	if (i > 0 && t_map.matrix[i - 1][j] != '1' &&
		t_map.matrix[i - 1][j] != '-')
		ft_exit("Error: Map error1!");
	if (i < t_map.rows - 1 && t_map.matrix[i + 1][j] != '1' &&
		t_map.matrix[i + 1][j] != '-')
		ft_exit("Error: Map error2!");
	if (j > 0 && t_map.matrix[i][j - 1] != '1' &&
		t_map.matrix[i][j - 1] != '-')
		ft_exit("Error: Map error3!");
	if (j < t_map.cols - 1 && t_map.matrix[i][j + 1] != '1' &&
		t_map.matrix[i][j + 1] != '-')
		ft_exit("Error: Map error4!");
}
