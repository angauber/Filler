/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler_start.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:27:06 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	solve_tab(char *line, char **board, int len, char p)
{
	FILE	*fd;
	char	**pattern;
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	fd = fopen("log.txt", "w+");
	while (line[++i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9' && x == 0)
			x = ft_atoi(&line[i]);
		else if (line[i] >= '0' && line[i] <= '9' && y == 0)
			y = ft_atoi(&line[i]);
	}
	fprintf(fd, "x: %d --> y: %d\n", x, y);
	pattern = malloc(sizeof(char **) * x);
	i = -1;
	while (++i < x)
	{
		j = 0;
		get_next_line(0, &line);
		while (line[j] != '\0')
			j++;
		pattern[i] = ft_strsub(line, 0, j);
		fprintf(fd, "pattern: %s\n", pattern[i]);
	}
	fprintf(fd, "player: %c\n", p);
	get_pattern(board, pattern, x, fd, p);
}

int		main()
{
	char	**board;
	char	*line;
	char	p;
	int		i;
	int		x;
	int		y;
	int		j;

	x = 0;
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "$$$") == NULL)
		x = 0;
	p = (line[10] == '1') ? 'O' : 'X';
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "Plateau") == NULL)
		x = 0;
	while (line[++i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (!x)
				x = ft_atoi(&line[i]);
			else
				y = ft_atoi(&line[i]);
			while (line[i] != '\0' && line[i] != ' ')
				i++;
		}
	}
	board = malloc(sizeof(char **) * x);
	j = 0;
	while (get_next_line(0, &line) != 0)
	{
		if (j == x)
		{
			solve_tab(line, board, x, p);
			j = 0;
		}
		if (line[0] >= '0' && line[0] <= '9')
		{
			board[j] = ft_strsub(line, 4, y + 4);
			j++;
		}
	}
	return (0);
}