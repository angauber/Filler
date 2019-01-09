/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler_start.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 18:48:47 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	free_2d_tab(char **tab, int i)
{
	int x;

	x = -1;
	while (++x < i)
		ft_strdel(&tab[x]);
}

void	free_2d_int_tab(int **tab, int i)
{
	int x;

	x = -1;
	while (++x < i)
	{
		free(tab[x]);
		tab[x] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	free_struct(t_filler *filler)
{
	free_2d_int_tab(filler->piece->coord, filler->piece->points);
	free(filler->piece);
	free(filler);
}

void	solve_tab(char *line, char **board, t_filler *filler)
{
	char	**pattern;
	char	**split;
	int		i;
	int		j;

	i = -1;
	split = ft_strsplit(line, ' ');
	filler->piece->height = ft_atoi(split[1]);
	filler->piece->width = ft_atoi(split[2]);
	pattern = malloc(sizeof(char *) * filler->piece->height);
	j = filler->piece->width;
	i = -1;
	while (++i < filler->piece->height)
	{
		get_next_line(0, &line);
		pattern[i] = ft_strdup(line);
		ft_strdel(&line);
	}
	get_pattern(board, pattern, filler);
	free_2d_tab(pattern, ft_atoi(split[1]));
	free(pattern);
	free_2d_tab(split, 3);
	free(split);
}

void		check_start(char **board, t_filler *filler)
{
	int i;
	int j;

	i = -1;
	while (++i < filler->board_height)
	{
		j = -1;
		while (++j < filler->board_width)
		{
			if (board[i][j] == filler->player)
			{
				filler->start_h = i;
				filler->start_w = j;
			}
		}
	}
}

t_filler	*init_struct(void)
{
	t_filler	*filler;
	t_piece		*piece;

	if (!(filler = malloc(sizeof(t_filler))))
		return (NULL);
	if (!(piece = malloc(sizeof(t_piece))))
		return (NULL);
	piece->height = 0;
	piece->width = 0;
	filler->piece = piece;
	filler->board_height = 0;
	filler->board_width = 0;
	return (filler);
}

int		main(void)
{
	t_filler	*filler;
	char		**split;
	char		**board;
	char		*line;
	int			j;
	int			first;

	first = 0;
	filler = init_struct();
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "$$$") == NULL)
		ft_strdel(&line);
	filler->player = (line[10] == '1') ? 'O' : 'X';
	ft_strdel(&line);
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "Plateau") == NULL)
		ft_strdel(&line);
	split = ft_strsplit(line, ' ');
	ft_strdel(&line);
	filler->board_height = ft_atoi(split[1]);
	filler->board_width = ft_atoi(split[2]);
	board = malloc(sizeof(char **) * filler->board_height);
	while (get_next_line(0, &line) != 0)
	{
		if (j == filler->board_height)
		{
			solve_tab(line, board, filler);
			if (first == 0)
				check_start(board, filler);
			first++;
			j = 0;
			free_2d_tab(board, filler->board_height);
		}
		if (line[0] >= '0' && line[0] <= '9')
		{
			board[j] = ft_strsub(line, 4, filler->board_width + 4);
			j++;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	free_struct(filler);
	free_2d_tab(split, 3);
	free(split);
	free(board);
	return (0);
}
