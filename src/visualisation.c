/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visualisation.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 13:43:39 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf/include/ft_printf.h"

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
	size_t i;

	i = 0;
	while (i < len)
	{
		put_line(board[i]);
		i++;
	}
	i = 0;
	usleep(100000);
	while (i < len)
	{
//		ft_printf("\033[1A");  // move cursor one line up
//		ft_printf("\033[2J"); // delete till end of line
		ft_printf("\033[2K"); // delete till end of line
		ft_printf("\033[1A");  // move cursor one line up
		i++;
	}
}

void	print_vs(char *s1, char *s2)
{
	ft_printf(KCYN "\n\t%s" RESET, s1);
	ft_printf("   VS   ");
	ft_printf(KMAG "%s" RESET, s2);
	ft_printf("\n\n");
}

int		main()
{
	char	**board;
	char	**split;
	char	*line;
	char	*s1;
	char	*s2;
	int		i;
	int		x;
	int		y;
	int		j;

	while (get_next_line(0, &line) != 0 && ft_strstr(line, "launched") == NULL)
		x = 0;
	while (line[x] != '/')
		x++;
	x++;
	i = x;
	while (line[i] != '.')
		i++;
	s1 = ft_strsub(line, x, i);
	while (get_next_line(0, &line) != 0 && ft_strstr(line, "launched") == NULL)
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
		x = 0;
	split = ft_strsplit(line, ' ');
	x = ft_atoi(split[1]);
	y = ft_atoi(split[2]);
	board = malloc(sizeof(char **) * x);
	j = 0;
	while (get_next_line(0, &line) != 0)
	{
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
	}
	i = 0;
	while (i < x)
	{
		put_line(board[i]);
		i++;
	}
	return (0);
}
