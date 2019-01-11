/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heatmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 15:36:10 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 11:56:20 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		**create_heat_map(char **board, t_filler *filler)
{
	int **map;
	int i;
	int j;

	if (!(map = (int **)malloc(sizeof(int *) * filler->board_height)))
		return (NULL);
	i = -1;
	while (++i < filler->board_height)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * filler->board_width)))
			return (NULL);
		j = -1;
		while (++j < filler->board_width)
		{
			if (board[i][j] == filler->player)
				map[i][j] = -1;
			else if (board[i][j] != '.')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	return (recursive_heat(map, filler));
}

void	cut_heat_00(int i, int j, int **map, t_filler *filler)
{
	if (j > 0 && map[i][j - 1] != 0 && map[i][j - 1] != -1)
		map[i][j] = map[i][j - 1];
	if (i > 0 && j > 0 && map[i - 1][j - 1] != 0 && map[i - 1]
	[j - 1] != -1 && (map[i - 1][j - 1] < map[i][j] || map[i][j]
	== 0))
		map[i][j] = map[i - 1][j - 1];
	if (i > 0 && map[i - 1][j] != 0 && map[i - 1][j] != -1 &&
	(map[i - 1][j] < map[i][j] || map[i][j] == 0))
		map[i][j] = map[i - 1][j];
	if (i > 0 && j < (filler->board_width - 1) && map[i - 1][j + 1]
	!= 0 && map[i - 1][j + 1] != -1 && (map[i - 1][j + 1] < map[i]
	[j] || map[i][j] == 0))
		map[i][j] = map[i - 1][j + 1];
}

void	cut_heat_01(int i, int j, int **map, t_filler *filler)
{
	if (j < (filler->board_width - 1) && map[i][j + 1] != 0 && map[i
	][j + 1] != -1 && (map[i][j + 1] < map[i][j] || map[i][j] == 0))
		map[i][j] = map[i][j + 1];
	if (i < (filler->board_height - 1) && j < (filler->board_width -
	1) && map[i + 1][j + 1] != 0 && map[i + 1][j + 1] != -1 && (map
	[i + 1][j + 1] < map[i][j] || map[i][j] == 0))
		map[i][j] = map[i + 1][j + 1];
	if (i < (filler->board_height - 1) && map[i + 1][j] != 0 && map
	[i + 1][j] != -1 && (map[i + 1][j] < map[i][j] ||
	map[i][j] == 0))
		map[i][j] = map[i + 1][j];
	if (i < (filler->board_height - 1) && j > 0 && map[i + 1][j - 1]
	!= 0 && map[i + 1][j - 1] != -1 && (map[i + 1][j - 1] <
	map[i][j] || map[i][j] == 0))
		map[i][j] = map[i + 1][j - 1];
}

int		**recursive_heat(int **map, t_filler *filler)
{
	int zero;
	int i;
	int j;

	zero = 0;
	i = -1;
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (map[i][j] == 0 || map[i][j] == -1)
			{
				cut_heat_00(i, j, map, filler);
				cut_heat_01(i, j, map, filler);
				if (map[i][j] != 0)
					map[i][j] += 1;
				else
					zero++;
			}
		}
	}
	if (zero > 0)
		recursive_heat(map, filler);
	return (map);
}
