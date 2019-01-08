/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heatmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 15:36:10 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:17:47 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		**create_heat_map(char **board, t_filler *filler)
{
	int **map;
	int i;
	int j;

	if (!(map = malloc(sizeof(int *) * filler->board_height)))
		return (NULL);
	for (i = 0; i < filler->board_height; i++)
	{
		if (!(map[i] = malloc(sizeof(int) * filler->board_width)))
			return (NULL);
	}
	i = -1;
	while (++i < filler->board_height)
	{
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
	recursive_heat(map, filler);
	return (map);
}

void	recursive_heat(int **map, t_filler *filler)
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
				if (j > 0 && map[i][j - 1] != 0 && map[i][j - 1] != -1)
					map[i][j] = map[i][j - 1];
				if (i > 0 && j > 0 && map[i - 1][j - 1] != 0 && map[i - 1][j - 1] != -1 && (map[i - 1][j - 1] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i - 1][j - 1];
				if (i > 0 && map[i - 1][j] != 0 && map[i - 1][j] != -1 && (map[i - 1][j] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i - 1][j];
				if (i > 0 && j < (filler->board_width - 1) && map[i - 1][j + 1] != 0 && map[i - 1][j + 1] != -1 && (map[i - 1][j + 1] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i - 1][j + 1];
				if (j < (filler->board_width - 1) && map[i][j + 1] != 0 && map[i][j + 1] != -1 && (map[i][j + 1] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i][j + 1];
				if (i < (filler->board_height - 1) && j < (filler->board_width - 1) && map[i + 1][j + 1] != 0 && map[i + 1][j + 1] != -1 && (map[i + 1][j + 1] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i + 1][j + 1];
				if (i < (filler->board_height - 1) && map[i + 1][j] != 0 && map[i + 1][j] != -1 && (map[i + 1][j] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i + 1][j];
				if (i < (filler->board_height - 1) && j > 0 && map[i + 1][j - 1] != 0 && map[i + 1][j - 1] != -1 && (map[i + 1][j - 1] < map[i][j] || map[i][j] == 0))
					map[i][j] = map[i + 1][j - 1];
				if (map[i][j] != 0)
					map[i][j] += 1;
				else
					zero++;
			}
		}
	}
	if (zero > 0)
		recursive_heat(map, filler);
}
