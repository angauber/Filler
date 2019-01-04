/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:17:56 by angauber    ###    #+. /#+    ###.fr     */
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

int		check_piece_top(char **board, int i, int j, t_filler *filler, int fd)
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
//	dprintf(fd, "\n\nfor i: %d <***> j: %d\n", i, j);
	while (++nb < filler->piece->points)
	{
		x = i + filler->piece->coord[nb][0] - height;
		y = j + filler->piece->coord[nb][1] - width;
		if (x >= filler->board_height || y >= filler->board_width || (x < filler->board_height && y < filler->board_width && (board[x][y] == enemy || (conection > 0 && board[x][y] != '.'))))
			return (0);
		else if (x < filler->board_height && y < filler->board_width && board[x][y] == filler->player)
			conection++;
//		dprintf(fd, "x, y: %d %d\n", x, y);
	}
	if (conection != 1)
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

	i = filler->board_height;
	while (i > 0)
	{
		j = filler->board_width;
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

int		find_coord_bottom(char **board, t_filler *filler, int fd)
{
	int i;
	int j;

	i = -1;
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (check_piece_top(board, i, j, filler, fd) == 1)
				return (1);
		}
	}
	return (0);
}

int		find_low_heat(int **map, t_filler *filler)
{
	int i;
	int j;
	int nb;

	i = -1;
	nb = 10000;
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (map[i][j] != 0 && map[i][j] < nb)
				nb = map[i][j];
		}
	}
	return (nb);
}

int		find_h(int **map, t_filler *filler, char c)
{
	int i;
	int j;
	int nb;

	nb = find_low_heat(map, filler);
	i = -1;
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (map[i][j] == nb)
			{
				if (c == 'h')
					return (i);
				else
					return (j);
			}
		}
	}
	return (-1);
}

int		BaseSupPos(char **board, t_filler *filler, int x, int y, int fd)
{
	int sup;

	sup = (y > filler->start_w) ? 1 : 0;
	while (x > filler->start_h)
	{
		while (y != filler->start_w)
		{
			if (check_piece_top(board, x, y, filler, fd) == 1)
				return (1);
			if (sup == 1)
				y--;
			else
				y++;
		}
		x--;
	}
	return (0);
}

int		BaseInfPos(char **board, t_filler *filler, int x, int y, int fd)
{
	int sup;

	sup = (y > filler->start_w) ? 1 : 0;
	while (x < filler->start_h)
	{
		while (y != filler->start_w)
		{
			if (check_piece_top(board, x, y, filler, fd) == 1)
				return (1);
			if (sup == 1)
				y--;
			else
				y++;
		}
		x++;
	}
	return (0);
}
int		find_coord_heat(char **board, t_filler *filler, int **map, int fd)
{
	int x;
	int y;

	x = find_h(map, filler, 'h');
	y = find_h(map, filler, 'w');
	if (x == -1 || y == -1)
	{
		dprintf(fd, "stop condition\n");
		return (0);
	}
	if (x > filler->start_h)
	{
		if (BaseSupPos(board, filler, x, y, fd) == 1)
			return (1);
	}
	else if (BaseInfPos(board, filler, x, y, fd) == 1)
		return (1);
	map[x][y] = 0;
	return (find_coord_heat(board, filler, map, fd));
}

int		**create_heat_map(char **board, t_filler *filler, int fd)
{
	int **map;
	int i;
	int j;

	i = -1;
	if (!(map = malloc(sizeof(int *) * filler->board_height)))
		return (NULL);
	while (++i < filler->board_height)
	{
		if (!(map[i] = malloc(sizeof(int) * filler->board_width)))
			return (NULL);
	}
	i = 1;
//	dprintf(fd, "start of hm :\n\n\n");
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (board[i][j] != filler->player && board[i][j] != '.')
				map[i][j] = (((i - filler->start_h) + (j - filler->start_w)) > 0) ? ((i - filler->start_h) + (j - filler->start_w)) : (((i - filler->start_h) + (j - filler->start_w)) * -1);
			else
				map[i][j] = 0;
//			dprintf(fd, "%d  ", map[i][j]);
		}
//		dprintf(fd, "\n");
	}
	return (map);
}

void	place_piece(char **board, t_filler *filler, int fd)
{
	int **heat_map;

	heat_map = create_heat_map(board, filler, fd);
	if (find_coord_heat(board, filler, heat_map, fd) == 0)
	{
		dprintf(fd, "bottom to top\n");
		if (filler->start_h > (filler->board_height / 2))
		{
			if (find_coord_bottom(board, filler, fd) == 0)
				ft_printf("0 0\n");
		}
		else if (find_coord_top(board, filler, fd) == 0)
			ft_printf("0 0\n");
	}
	else
		dprintf(fd, "Heatmap\n");
}
