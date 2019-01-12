/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 14:05:21 by angauber    ###    #+. /#+    ###.fr     */
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

	nb = -1;
	conection = 0;
	while (++nb < filler->piece->points)
	{
		x = pos[0] + filler->piece->coord[nb][0];
		y = pos[1] + filler->piece->coord[nb][1];
		conection += map[x][y];
	}
	return (conection);
}

int		cut_end_fch(int new, int *pos, int *bestpos)
{
	if (new == 0)
	{
		free(pos);
		free(bestpos);
		return (0);
	}
	ft_printf("%d %d\n", bestpos[0], bestpos[1]);
	free(pos);
	free(bestpos);
	return (1);
}

int		*actual_pos(int i, int j)
{
	int *array;

	if (!(array = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	array[0] = i;
	array[1] = j;
	return (array);
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
			if (check_placable_piece(board, filler, pos, actual_pos(i, j)) == 1)
			{
				if (new == 0 || point_pos(pos, map, filler) <
				point_pos(bestpos, map, filler))
					change_best(pos, bestpos);
				new = 1;
			}
		}
	}
	return (cut_end_fch(new, pos, bestpos));
}

void	place_piece(char **board, t_filler *filler)
{
	int **heat_map;

	heat_map = create_heat_map(board, filler);
	if (find_coord_heat(board, filler, heat_map) == 0)
		ft_printf("0 0\n");
	free_2d_int_tab(heat_map, filler->board_height);
}
