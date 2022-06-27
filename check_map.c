/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veronica <veronica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:34:22 by vlyubick          #+#    #+#             */
/*   Updated: 2022/06/07 00:41:06 by veronica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rectangle(char **mapdata)
{
	int	i;
	int	w;

	w = ft_strlen(mapdata[0]);
	i = 1;
	while (mapdata[i] != NULL)
	{
		if ((int)ft_strlen(mapdata[i]) != w)
		{
			freemap(mapdata);
			errors(4);
		}
		i++;
	}
}

void	ft_wallsaround(char **mapdata)
{
	int		x;
	int		y;
	int		w;
	int		h;

	x = 0;
	y = 0;
	w = ft_strlen(mapdata[0]);
	h = mapheight(mapdata);
	while (mapdata[0][x] != '\0')
	{
		if (mapdata[0][x] != '1' || mapdata[h - 1][x] != '1')
			errors(5);
		x++;
	}
	while (y < h)
	{
		if (mapdata[y][0] != '1' || mapdata[y][w - 1] != '1')
			errors(5);
		y++;
	}
}

void	ft_symbols(char **mapdata)
{
	int	x;
	int	y;

	y = 0;
	while (mapdata[y])
	{
		x = 0;
		while (mapdata[y][x])
		{
			if (mapdata[y][x] != '1' && mapdata[y][x] != '0'
				&& mapdata[y][x] != 'C' && mapdata[y][x] != 'E'
				&& mapdata[y][x] != 'P')
				errors(6);
			x++;
		}
		y++;
	}
}

void	ft_countchars(t_gen *gen)
{
	int	x;
	int	y;

	y = -1;
	gen->player = 0;
	gen->score = 0;
	gen->escape = 0;
	while (gen->mapdata[++y])
	{
		x = -1;
		while (gen->mapdata[y][++x])
		{
			if (gen->mapdata[y][x] == 'P')
				gen->player += 1;
			if (gen->mapdata[y][x] == 'C')
				gen->score += 1;
			if (gen->mapdata[y][x] == 'E')
				gen->escape += 1;
		}
	}
	if (gen->player != 1 || gen->escape != 1)
		errors(7);
	if (gen->score == 0)
		errors(8);
}

void	check_map(t_gen *gen)
{
	ft_rectangle(gen->mapdata);
	ft_wallsaround(gen->mapdata);
	ft_symbols(gen->mapdata);
	ft_countchars(gen);
}
