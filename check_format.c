/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veronica <veronica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:29:38 by vlyubick          #+#    #+#             */
/*   Updated: 2022/06/07 00:36:43 by veronica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *arg, t_gen *gen)
{
	int		fd;
	char	*all;
	char	*line;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		errors(3);
	all = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		all = gl_strjoin(all, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);	
	gen->mapdata = ft_split(all, '\n');
}

void	init_game(t_gen *gen)
{
	gen->width = ft_strlen(gen->mapdata[0]);
	gen->height = mapheight(gen->mapdata);
	gen->mlx = mlx_init();
	gen->win = mlx_new_window(gen->mlx, 64 * gen->width, 64 * gen->height, "so_long");
	gen->currscore = 0;
	gen->steps = 0;
}

void	pposition(t_gen *gen)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (gen->mapdata[y] != NULL)
	{
		x = 0;
		while (gen->mapdata[y][x] != '\0')
		{
			if (gen->mapdata[y][x] == 'P')
			{
				gen->xpos = x;
				gen->ypos = y;
				return ;
			}
			x++;
		}
	y++;
	}
}

void	check_format(char *arg, t_gen *gen)
{
	char	*ber;
	// t_gen	*gen;

	// gen = malloc(sizeof(t_gen));
	ber = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (ber == NULL)
		errors(2);
	if (ber)
	{
		read_map(arg, gen);
		pposition(gen);
		check_map(gen);
		init_game(gen);
		init_map(gen);
		//game_hook(gen);
		//mlx_loop(gen->mlx);
	}
}
			