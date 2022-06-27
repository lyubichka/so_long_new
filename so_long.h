/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 04:44:14 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/27 06:42:14 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>


typedef struct s_gen
{
	void		*mlx;
	void		*win;
	char		**mapdata;
	int			height;
	int			width;
	int			xpos;
	int			ypos;
	int			player;
	int			score;
	int			currscore;
	int			steps;
	int			escape;
	void		*img;
}	t_gen;

# define IMG_W  "./images/wall.xpm"
# define IMG_P  "./images/dog.xpm"
# define IMG_C  "./images/meat.xpm"
# define IMG_E  "./images/exit.xpm"
# define IMG_S  "./images/floor.xpm"
# define IMG_EN "./images/nika.xpm"

# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define ESC 53

void		check_format(char *arg, t_gen *gen);
void		check_map(t_gen *gen);
int			game_over(t_gen *gen);
void		errors(int n);
void		freemap(char **mapdata);
int			mapheight(char **mapdata);
int			game_over(t_gen *gen);
void		ig_draw(t_gen *gen, int img, int x, int y);
void		ig_draw_c(t_gen *gen, int j, int i);
void		ig_draw_p(t_gen *gen, int j, int i);
void		init_map(t_gen *gen);
void		game_hook(t_gen *gen);
int			moving(t_gen *gen, int x, int y);
int			key_press(int keycode, t_gen *gen);

#endif