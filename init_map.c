/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:04:16 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/27 03:29:31 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ig_draw(t_gen *gen, int img, int x, int y)
{
	void	*ptr;
	char	*s;
	int		size;

	size = 64;
	if (img == 1)
		s = IMG_W;
	else if (img == 2)
		s = IMG_P;
	else if (img == 3)
		s = IMG_S;
	else if (img == 4)
		s = IMG_C;
	else if (img == 5)
		s = IMG_E;
	else if (img == 6)
		s = IMG_EN;
	ptr = mlx_xpm_file_to_image(gen->mlx, s, &size, &size);
	mlx_put_image_to_window(gen->mlx, gen->win, ptr, x * 64, y * 64);
	mlx_destroy_image(gen->mlx, ptr);
}

void	ig_draw_c(t_gen *gen, int j, int i)
{
	ig_draw(gen, 3, j, i);
	ig_draw(gen, 4, j, i);
	gen->currscore++;
}

void	ig_draw_p(t_gen *gen, int j, int i)
{
	ig_draw(gen, 3, j, i);
	ig_draw(gen, 2, j, i);
	gen->width = j;
	gen->height = i;
}

void	init_map(t_gen *gen)
{
	int		i;
	int		j;

	i = 0;
	while (gen->mapdata[i] != NULL)
	{
		j = 0;
		while (gen->mapdata[i][j] != '\0')
		{
			if (gen->mapdata[i][j] == '1')
				ig_draw(gen, 1, j, i);
			else if (gen->mapdata[i][j] == 'P')
				ig_draw_p(gen, j, i);
			else if (gen->mapdata[i][j] == '0')
				ig_draw(gen, 3, j, i);
			else if (gen->mapdata[i][j] == 'C')
				ig_draw_c(gen, j, i);
			else if (gen->mapdata[i][j] == 'E')
				ig_draw(gen, 5, j, i);
			else if (gen->mapdata[i][j] == 'F')
				ig_draw(gen, 6, j, i);
			j++;
		}
		i++;
	}
}
