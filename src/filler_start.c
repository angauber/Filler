/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler_start.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 14:36:18 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	solve_tab(char *line, char **board, t_filler *filler)
{
	int		fd;
	char	**pattern;
	char	**split;
	int		i;
	int		j;

	i = -1;
	fd = open("log.txt", O_TRUNC | O_RDWR);
	split = ft_strsplit(line, ' ');
	filler->piece->height = ft_atoi(split[1]);
	filler->piece->width = ft_atoi(split[2]);
	pattern = malloc(sizeof(char *) * filler->piece->height);
	j = filler->piece->width;
	dprintf(fd, "height: %d width: %d \n\n", filler->piece->height, filler->piece->width);
	i = -1;
	while (++i < filler->piece->height)
	{
		get_next_line(0, &line);
		pattern[i] = ft_strdup(line);
	}
	dprintf(fd, "pattern: \n\n");
	for (i=0; i<filler->piece->height; i++)
		dprintf(fd, "%s\n", pattern[i]);
	get_pattern(board, pattern, fd, filler);
	for (i=0; i<filler->board_height; i++)
		dprintf(fd, "%s\n", board[i]);
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

int		main()
{
	t_filler	*filler;
	char		**split;
	char		**board;
	char		*line;
	int			i;
	int			j;
	int			first;

	first = 0;
	filler = init_struct();
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "$$$") == NULL)
		j = 0;
	filler->player = (line[10] == '1') ? 'O' : 'X';
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "Plateau") == NULL)
		j = 0;
	split = ft_strsplit(line, ' ');
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
		}
		if (line[0] >= '0' && line[0] <= '9')
		{
			board[j] = ft_strsub(line, 4, filler->board_width + 4);
			j++;
		}
	}
	return (0);
}
