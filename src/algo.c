/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:16:17 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		point_pos(int *pos, int **map, t_filler *filler)
{
	int		nb;
	int		x;
	int		y;
	int		conection;
	char	enemy;
	
	nb = -1;
	conection = 0;
	enemy = (filler->player == 'O') ? 'X' : 'O';
	while (++nb < filler->piece->points)
	{
		x = pos[0] + filler->piece->coord[nb][0];
		y = pos[1] + filler->piece->coord[nb][1];
		conection += map[x][y];
	}
	return (conection);
}

int		find_coord_heat(char **board, t_filler *filler, int **map)
{
	int i;
	int j;
	int new;
	int *pos;
	int *bestpos;

	pos = malloc(sizeof(int) * 2);
	bestpos = malloc(sizeof(int) * 2);
	new = 0;
	i = -1;
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (check_placable_piece(board, i, j, filler, pos) == 1)
			{
				if (new == 0 || point_pos(pos, map, filler) < point_pos(bestpos, map, filler))
				{
					bestpos[0] = pos[0];
					bestpos[1] = pos[1];
				}
				new = 1;
			}
		}
	}
	if (new == 0)
		return (0);
	else
		ft_printf("%d %d\n", bestpos[0], bestpos[1]);
	return (1);
}

void	place_piece(char **board, t_filler *filler)
{
	int **heat_map;

	heat_map = create_heat_map(board, filler);
	if (find_coord_heat(board, filler, heat_map) == 0)
		ft_printf("0 0\n");
}
