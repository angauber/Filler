/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visualisation.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 17:28:30 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
		ft_strdel(&board[i]);
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

void	print_end(char *line)
{
	int i;
	int j;

	ft_printf("\033[2K");
	ft_printf("\033[1A");
	if (line[3] == 'O')
	{
		i = ft_atoi(&line[10]);
		ft_strdel(&line);
		get_next_line(0, &line);
		j = ft_atoi(&line[10]);
		ft_strdel(&line);
	}
	else
	{
		j = ft_atoi(&line[10]);
		ft_strdel(&line);
		get_next_line(0, &line);
		i = ft_atoi(&line[10]);
		ft_strdel(&line);
	}
	ft_printf(KCYN "\n\t\t\t%d" RESET, i);
	ft_printf("   VS   ");
	ft_printf(KMAG "%d\n" RESET, j);
}

void	board(char *line, int x, int y)
{
	char	**board;
	char	**split;
	int		j;

	split = ft_strsplit(line, ' ');
	x = ft_atoi(split[1]);
	y = ft_atoi(split[2]);
	ft_strdel(&split[0]);
	ft_strdel(&split[1]);
	ft_strdel(&split[2]);
	free(split);
	ft_strdel(&line);
	j = 0;
	board = malloc(sizeof(char **) * x);
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strstr(line, "fin") != NULL)
		{
			print_end(line);
			return ;
		}
		if (j == x)
		{
			print_tab(board, x);
			j = 0;
		}
		if (line[0] >= '0' && line[0] <= '9')
		{
			board[j] = ft_strsub(line, 4, y + 4);
			j++;
		}
		ft_strdel(&line);
	}
	free(board);
	ft_strdel(&line);
}

void	visual(char *line, int x, int i)
{
	char	*s1;
	char	*s2;

	s1 = ft_strsub(line, x, i);
	ft_strdel(&line);
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
	ft_strdel(&line);
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "Plateau") == NULL)
		ft_strdel(&line);
	ft_strdel(&s1);
	ft_strdel(&s2);
	board(line, 0, 0);
}

int		main(void)
{
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
