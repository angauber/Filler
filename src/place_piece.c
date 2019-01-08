/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:16:36 by angauber    ###    #+. /#+    ###.fr     */
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

int		check_placable_piece(char **board, int i, int j, t_filler *filler, int *pos)
{
	int		nb;
	int		x;
	int		y;
	int		width;
	int		height;
	int		conection;
	char	enemy;
	
	nb = -1;
	conection = 0;
	width = free_width(filler->piece);
	height = free_height(filler->piece);
	enemy = (filler->player == 'O') ? 'X' : 'O';
	while (++nb < filler->piece->points)
	{
		x = i + filler->piece->coord[nb][0] - height;
		y = j + filler->piece->coord[nb][1] - width;
		if (x >= filler->board_height || y >= filler->board_width || (x < filler->board_height && y < filler->board_width && (board[x][y] == enemy || (conection > 0 && board[x][y] != '.'))))
			return (0);
		else if (x < filler->board_height && y < filler->board_width && board[x][y] == filler->player)
			conection++;
	}
	if (conection != 1)
		return (0);
	pos[0] = (i - height);
	pos[1] = (j - width);
	return (1);
}