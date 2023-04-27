/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intonoya <intonoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:26:39 by intonoya          #+#    #+#             */
/*   Updated: 2023/04/27 22:12:32 by intonoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1
# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000
# define TEXTURE_SIZE 64
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h" 
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_img
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_line
{
	char	*line;
	char	*buff;
	char	*tmp;
	char	*ptr;
}				t_line;

struct s_map
{
	t_img		data;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_keys		keys;
	int			f_color[3];
	int			c_color[3];
	int			rows_tmp;
	int			rows;
	int			cols;
	char		**tmp_map;
	char		**matrix;
}				t_map;

int		ft_exit(char *str);
int 	file_exists(char *filename);
int 	check_extension(char *fn, char *fm);
int		check_map_name(char *string, char *extansion);
int 	is_space(char *str);
void    check_invalid_characters1(int i, int j);
int		check_invalid_characters2(void);

#endif