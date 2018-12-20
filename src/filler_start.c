/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler_start.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 14:10:04 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	solve_tab(char *line, char **board, t_filler *filler)
{
	FILE	*fd;
	char	**pattern;
	int		i;
	int		j;

	i = -1;
	fd = fopen("log.txt", "w+");
	while (line[++i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9' && filler->piece->height == 0)
			filler->piece->height = ft_atoi(&line[i]);
		else if (line[i] >= '0' && line[i] <= '9' && filler->piece->width == 0)
			filler->piece->width = ft_atoi(&line[i]);
	}
	pattern = malloc(sizeof(char **) * filler->piece->height);
	i = -1;
	while (++i < filler->piece->height)
	{
		j = 0;
		get_next_line(0, &line);
		while (line[j] != '\0')
			j++;
		pattern[i] = ft_strsub(line, 0, j);
	}
	get_pattern(board, pattern, fd, filler);
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
	return (filler);
}

int		main()
{
	t_filler	*filler;
	char		**board;
	char		*line;
	int			i;
	int			j;

	filler = init_struct();
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "$$$") == NULL)
		j = 0;
	filler->player = (line[10] == '1') ? 'O' : 'X';
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "Plateau") == NULL)
		j = 0;
	while (line[++i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (filler->board_height == 0)
				filler->board_height = ft_atoi(&line[i]);
			else
				filler->board_width = ft_atoi(&line[i]);
			while (line[i] != '\0' && line[i] != ' ')
				i++;
		}
	}
	board = malloc(sizeof(char **) * filler->board_height);
	while (get_next_line(0, &line) != 0)
	{
		if (j == filler->board_height)
		{
			solve_tab(line, board, filler);
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
