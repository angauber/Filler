/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 13:36:45 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		free_height(t_piece *piece)
{
	int height;
	int nb;

	nb = -1;
	height = piece->coord[0][0];
	while (++nb < piece->points)
	{
		if (piece->coord[nb][0] < height)
			height = piece->coord[nb][0];
	}
	return (height);
}

int		free_width(t_piece *piece)
{
	int width;
	int nb;

	nb = -1;
	width = piece->coord[0][1];
	while (++nb < piece->points)
	{
		if (piece->coord[nb][1] < width)
			width = piece->coord[nb][1];
	}
	return (width);
}

void	change_pos(t_filler *filler, int *pos, int *actpos)
{
	pos[0] = (actpos[0] - filler->piece->height);
	pos[1] = (actpos[1] - filler->piece->width);
	free(actpos);
}

int		free_cpp(int *actpos)
{
	free(actpos);
	return (0);
}

int		check_placable_piece(char **board, t_filler *filler, int *pos,
		int *actpos)
{
	int		nb;
	int		x;
	int		y;
	int		conection;

	nb = -1;
	conection = 0;
	filler->piece->width = free_width(filler->piece);
	filler->piece->height = free_height(filler->piece);
	while (++nb < filler->piece->points)
	{
		x = actpos[0] + filler->piece->coord[nb][0] - filler->piece->height;
		y = actpos[1] + filler->piece->coord[nb][1] - filler->piece->width;
		if (x >= filler->board_height || y >= filler->board_width || (x <
		filler->board_height && y < filler->board_width && (board[x][y] ==
		filler->enemy || (conection > 0 && board[x][y] != '.'))))
			return (free_cpp(actpos));
		else if (x < filler->board_height && y < filler->board_width &&
		board[x][y] == filler->player)
			conection++;
	}
	if (conection != 1)
		return (free_cpp(actpos));
	change_pos(filler, pos, actpos);
	return (1);
}
