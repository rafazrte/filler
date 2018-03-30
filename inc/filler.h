/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:57:11 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/30 09:39:19 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../src/libft/libft.h"
#include <limits.h>

/*
**	STRUCTURES
*/

typedef	struct s_player
{
	int		n;
	char	c;
}				t_player;

typedef	struct s_board
{
	int		width;
	int		height;
	int		center;
	int		center_coords[2];
	char	**map;
}				t_board;

typedef	struct	s_piece
{
	int		width;
	int		height;
	int		cells;
	int		head[2];
	int		**coords;
	int		**adjusted_coords;
	char	**map;
}				t_piece;

typedef	struct	s_filler
{
	FILE		*fp;
	t_player	*player;
	t_board		*board;
	t_piece		*piece;
}				t_filler;

/*
**	MACROS 
*/

# define TRUE 1
# define FALSE 0
# define LOG_FILE "game_log.txt"

/*
**	MAIN FUNCTIONS
*/

void	initialize_game(t_filler *game);

/*
**	PARSING
*/

void	get_player_data(t_filler *game);
void	get_turn_data(t_filler *game);
void	generate_piece_metadata(t_filler *game);

/*
**	ALGORITHM
*/

/*
**	VISUALIZER
*/

/*
**	UTILITIES
*/

void	get_y_and_x(t_filler *game);

#endif
