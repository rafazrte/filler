/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre-processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:18:34 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/30 09:10:04 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Finds and stores coordinates of the piece's cells
*/

static	void	get_piece_coords(t_filler *game)
{
	int x;
	int y;
	int i;

	i = 0;
	game->piece->coords = (int **)ft_memalloc(sizeof(int *) * game->piece->cells);
	y = -1;
	while (++y < game->piece->height)
	{
		x = -1;
		while (++x < game->piece->width)
		{
			if (game->piece->map[y][x] == '*')
			{
				game->piece->coords[i] = (int *)ft_memalloc(sizeof(int) * 2);
				game->piece->coords[i][0] = y;
				game->piece->coords[i][1] = x;
			}
		}
	}
}

/*
**	Adjust coordinates relative to the head for easier
**	placing in the board
*/

static	void	adjust_piece_coords(t_filler *game)
{
	int i;

	i = 0;
	game->piece->adjusted_coords = (int **)ft_memalloc(sizeof(int *) * game->piece->cells);
	while (++i < game->piece->cells)
	{
		game->piece->adjusted_coords[i][0] = game->piece->coords[0][0] - game->piece->coords[i][0];
		game->piece->adjusted_coords[i][1] = game->piece->coords[0][1] - game->piece->coords[i][1];
	}
}

/*
**	Generate piece metadata for easier manipulation
*/

void	generate_piece_metadata(t_filler *game)
{
	get_piece_coords(game);
	adjust_piece_coords(game);
}
