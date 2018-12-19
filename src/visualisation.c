/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visualisation.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:19:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 15:28:54 by angauber    ###    #+. /#+    ###.fr     */
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
//	while (i < len)
//	{
//		ft_printf("\033[1A");  // move cursor one line up
		ft_printf("\033[2J"); // delete till end of line
//		i++;
//	}
}

int		main()
{
	char	**board;
	char	*line;
	int		i;
	int		x;
	int		y;
	int		j;

	i = -1;
	x = 0;
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
			print_tab(board, x);
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