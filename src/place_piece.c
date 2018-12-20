/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 16:34:45 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		top_height(t_filler *filler)
{
	int i;
	int nb;

	nb = filler->piece->coord[0][0];
	i = -1;
	while (++i < filler->piece->points)
	{
		if (filler->piece->coord[i][0] < nb)
			nb = filler->piece->coord[i][0];
	}
	return (nb);
}

int		left_width(t_filler *filler)
{
	int i;
	int nb;

	nb = filler->piece->coord[0][0];
	i = -1;
	while (++i < filler->piece->points)
	{
		if (filler->piece->coord[i][1] < nb)
			nb = filler->piece->coord[nb][1];
	}
	return (nb);
}

int		check_piece_top(char **board, int i, int j, t_filler *filler)
{
	int		nb;
	int		x;
	int		y;
	char	enemy;
	
	nb = -1;
	enemy = (filler->player == 'O') ? 'X' : 'O';
	while (++nb < filler->piece->points)
	{
		x = i + filler->piece->coord[nb][0] - (filler->piece->prev_h - filler->piece->height);
		y = j + filler->piece->coord[nb][1] - (filler->piece->prev_w - filler->piece->width);
		if (x < filler->board_height && y < filler->board_width && board[x][y] == enemy)
			return (0);
	}
	i -= top_height(filler);
	j -= left_width(filler);
	ft_printf("toph %d topw %d\n", top_height(filler), left_width(filler));
	ft_printf("%d %d\n", i, j);
	return (1);
}

int		find_coord_top(char **board, t_filler *filler)
{
	int i;
	int j;

	i = filler->board_height - 1;
	while (i >= 0)
	{
		j = filler->board_width - 1;
		while (j > 0)
		{
			if (board[i][j] == filler->player)
			{
				if (check_piece_top(board, i, j, filler) == 1)
					return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}


void	place_piece(char **board, t_filler *filler)
{
	if (find_coord_top(board, filler) == 0)
		ft_printf("0 0\n");
}

// coord du x plus proche - coord pattern == result (x y)