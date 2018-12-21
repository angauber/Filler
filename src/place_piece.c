/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 16:50:54 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		check_piece_top(char **board, int i, int j, t_filler *filler, int fd)
{
	int		nb;
	int		x;
	int		y;
	int		width;
	int		height;
	int		dot;
	char	enemy;
	
	nb = -1;
	dot = 0;
	width = filler->piece->coord[0][1];
	height = filler->piece->coord[0][0];
	enemy = (filler->player == 'O') ? 'X' : 'O';
	dprintf(fd, "\n\nfor i: %d <***> j: %d\n", i, j);
	while (++nb < filler->piece->points)
	{
		x = i + filler->piece->coord[nb][0] - height;
		y = j + filler->piece->coord[nb][1] - width;
		if (x >= filler->board_height || y >= filler->board_width || (x < filler->board_height && y < filler->board_width && (board[x][y] == enemy || (dot > 0 && board[x][y] != '.'))))
			return (0);
		else if (x < filler->board_height && y < filler->board_width && board[x][y] == filler->player)
			dot++;
		dprintf(fd, "x, y: %d %d\n", x, y);
	}
	if (dot != 1)
		return (0);
	ft_printf("%d %d\n", i - height, j - width);
	dprintf(fd, "h %d w %d\n", height, width);
	dprintf(fd, "%d %d\n", i - height, j - width);
	return (1);
}

int		find_coord_top(char **board, t_filler *filler, int fd)
{
	int i;
	int j;

	i = filler->board_height - 1;
	while (i >= 0)
	{
		j = filler->board_width - 1;
		while (j > 0)
		{
			if (check_piece_top(board, i, j, filler, fd) == 1)
				return (1);
			j--;
		}
		i--;
	}
	return (0);
}

void	place_piece(char **board, t_filler *filler, int fd)
{
	if (find_coord_top(board, filler, fd) == 0)
		ft_printf("0 0\n");
}
