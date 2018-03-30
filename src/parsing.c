/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 04:03:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/30 07:10:02 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Get player number and set the corresponding character
*/

void			get_player_data(t_filler *game)
{
	char	*line;
	
	get_next_line(0, &line);
	game->player->n = ft_atoi(ft_strchr(line, 'p') + 1);
	if (game->player->n == 1)
		game->player->c = 'o';
	else if (game->player->n == 2)
		game->player->c = 'x';
	// fputc(game->player->c, game->fp);fputc('\n', game->fp);
}
/*
**	Read board's dimensions, parse it and store it in 2d char array
*/

static	void	get_board_data(t_filler *game)
{
	char	*line;
	int		*height_width;
	int		x;
	int		y;
	
	y = -1;
	get_next_line(0, &line);
	height_width = get_y_and_x(line);
	game->board->height = height_width[0];
	game->board->width = height_width[1];
	free(height_width);
	get_next_line(0, &line);
	game->board->map = (char **)ft_memalloc(sizeof(char *) * game->board->height);
	while (++y < game->board->height)
	{
		x = 3;
		game->board->map[y] = ft_strnew(game->board->width);
		get_next_line(0, &line);
		while (++x < game->board->width + 4)
			game->board->map[y][x - 4] = line[x];
		fputs(game->board->map[y], game->fp);fputc('\n', game->fp);
	}
}

/*
**	Read piece's dimensions, parse it and store it in 2d char array
*/

static	void	get_piece_data(t_filler *game)
{
	char	*line;
	int		*height_width;
	int		x;
	int		y;

	y = -1;
	get_next_line(0, &line);
	height_width = get_y_and_x(line);
	game->piece->height = height_width[0];
	game->piece->width = height_width[1];
	free(height_width);
	game->piece->map = (char **)ft_memalloc(sizeof(char *) * game->piece->height);
	while (++y < game->piece->height)
	{
		x = -1;
		game->piece->map[y] = ft_strnew(game->piece->width);
		get_next_line(0, &line);
		while (++x < game->piece->width)
		{
			game->piece->map[y][x] = line[x];
			if (game->piece->map[y][x] == '*')
				game->piece->area++;
			fputs(game->piece->map[y], game->fp);fputc('\n', game->fp);
		}
	}
}

/*
**	Generate piece metadata for easier manipulation
*/

// void	generate_piece_metadata(t_filler *game)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < game->board)
// }

/*
**	Single function that controls the flow of the parsing
*/

void			get_turn_data(t_filler *game)
{
	t_piece		*piece;
	t_board		*board;

	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	board = (t_board *)ft_memalloc(sizeof(t_board));
	game->board = board;
	game->piece = piece;
	get_board_data(game);
	get_piece_data(game);
	// generate_piece_metadata(game);
}
