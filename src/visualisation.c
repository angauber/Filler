/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visualisation.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 15:25:31 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../src/filler.h"

#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KGRN  "\x1B[32m"
#define RESET "\x1B[0m"

void	put_line(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == 'X')
			ft_printf(KMAG "X" RESET);
		else if (str[i] == 'O')
			ft_printf(KCYN "O" RESET);
		else if (str[i] == 'x')
			ft_printf(KMAG "x" RESET);
		else if (str[i] == 'o')
			ft_printf(KCYN "o" RESET);
		else
			ft_putchar('.');
		ft_printf(" ");
	}
	ft_putchar('\n');
}

void	print_tab(char **board, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		put_line(board[i]);
	}
	usleep(100000);
	i = -1;
	while (++i < len)
	{
		ft_printf("\033[2K");
		ft_printf("\033[1A");
	}
}

void	print_vs(char *s1, char *s2)
{
	ft_printf(KCYN "\n\t%s" RESET, s1);
	ft_printf("   VS   ");
	ft_printf(KMAG "%s" RESET, s2);
	ft_printf("\n\n");
}

void	print_map(char **board, int x)
{
	int i;

	i = -1;
	while (++i < x)
	{
		put_line(board[i]);
		ft_strdel(&board[i]);
	}
	free(board);
}

void	board(char *line, int x, int y)
{
	char	**board;
	char	**split;
	int		j;

	split = ft_strsplit(line, ' ');
	x = ft_atoi(split[1]);
	y = ft_atoi(split[2]);
	j = 0;
	board = malloc(sizeof(char **) * x);
	while (get_next_line(0, &line) != 0)
	{
		if (j == x)
		{
			print_tab(board, x);
			for (int i = 0; i < x; i++)
				ft_strdel(&board[i]);
			j = 0;
		}
		if (line[0] >= '0' && line[0] <= '9')
		{
			board[j] = ft_strsub(line, 4, y + 4);
			j++;
		}
		ft_strdel(&line);
	}
	print_map(board, x);
}

void	visual(char *line, int x, int i)
{
	char	*s1;
	char	*s2;

	s1 = ft_strsub(line, x, i);
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "launched") == NULL)
		ft_strdel(&line);
	x = 0;
	while (line[x] != '/')
		x++;
	x++;
	i = x;
	while (line[i] != '.')
		i++;
	s2 = ft_strsub(line, x, i);
	print_vs(s1, s2);
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "Plateau") == NULL)
		ft_strdel(&line);
	board(line, 0, 0);
}

int		main(void)
{
	char	**board;
	char	**split;
	char	*line;
	int		i;
	int		x;

	x = 0;
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "launched") == NULL)
		ft_strdel(&line);
	while (line[x] != '/')
		x++;
	x++;
	i = x;
	while (line[i] != '.')
		i++;
	visual(line, x, i);
	return (0);
}
