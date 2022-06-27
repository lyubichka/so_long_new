/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:38:20 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/27 05:17:31 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_gen	*gen;

	gen = malloc(sizeof(t_gen));
	if (argc == 2)
	{
		check_format(argv[1], gen);
	}
	else
		errors(1);
	mlx_hook(gen->win, 2, 1L << 0, key_press, gen);
	mlx_hook(gen->win, 17, 0, game_over, gen);
	mlx_loop(gen->mlx);
	return (0);
}
