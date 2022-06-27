/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veronica <veronica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:55:12 by vlyubick          #+#    #+#             */
/*   Updated: 2022/06/07 00:38:09 by veronica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_gen *gen)
{
	int		y;
	int		x;

	if (keycode == 65307)
		game_over(gen);
	else if (keycode == 119)
		moving(gen, 0, -1);
	else if (keycode == 97)
		moving(gen, -1, 0);
	else if (keycode == 115)
		moving(gen, 0, 1);
	else if (keycode == 100)
		moving(gen, 1, 0);
	return (0);
}

int	move_errors(t_gen *gen, int x, int y)
{
	char	**s;

	s = gen->mapdata;
	if (s[y][x] == '1')
		return (1);
	if (s[y][x] == 'C')
	{
		gen->currscore++;
		gen->score--;
		s[y][x] = '0';
		ig_draw_p(gen, x, y);
		return (0);
	}
	if (s[y][x] == 'E' && gen->score != 0)
		return (1);
	if (s[y][x] == 'E' && gen->score == 0)
		game_over(gen);
}

int	moving(t_gen *gen, int x, int y)
{
	int	x_new;
	int	y_new;

	x_new = gen->xpos + x;
	y_new = gen->ypos + y;
	if (move_errors(gen, x_new, y_new) == 1)
		return (0);
	ig_draw(gen, 3, x_new, y_new);
	ig_draw(gen, 3, gen->xpos, gen->ypos);
	ig_draw(gen, 2, x_new, y_new);
	gen->mapdata[gen->ypos][gen->xpos] = '0';
	gen->mapdata[y_new][x_new] = 'P';
	gen->xpos = x_new;
	gen->ypos = y_new;
	gen->steps++;
	printf("Steps: %d\n", gen->steps);
	return (0);
}
