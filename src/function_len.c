/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_len.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:53:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:27:30 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		max_width(char **str, int nb)
{
	int i;
	int j;
	int width;

	j = -1;
	width = ft_strlen(str[0]);
	while (++j < ft_strlen(str[0]))
	{
		i = -1;
		while (++i < nb)
		{
			if (str[i][j] == '*')
				break;
		}
		if (i == nb)
			width--;
	}
	return (width);
}

int		max_height(char **str, int nb)
{
	int i;
	int j;
	int height;

	i = -1;
	height = nb;
	while (++i < nb)
	{
		j = -1;
		while (str[i][++j] != '\0')
		{
			if (str[i][j] == '*')
				break;
		}
		if (j == ft_strlen(str[0]))
			height--;
	}
	return (height);
}

void	find_pos(int **pos, char **pattern, int x)
{
	int i;
	int j;
	int z;

	i = -1;
	z = 0;
	while (++i < x)
	{
		j = -1;
		while (++j < ft_strlen(pattern[0]))
		{
			if (pattern[i][j] == '*')
			{
				pos[z] = malloc(sizeof(int *) * 2);
				pos[z][0] = i;
				pos[z][1] = j;
				z++;
			}
		}
	}
}

int		nb_point(char **pattern, int x)
{
	int i;
	int j;
	int ctr;

	ctr = 0;
	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < ft_strlen(pattern[0]))
		{
			if (pattern[i][j] == '*')
				ctr++;
		}
	}
	return (ctr);
}

void	get_pattern(char **board, char **pattern, int x, FILE *fd, char p)
{
	int width;
	int height;
	int **pos;

	width = max_width(pattern, x);
	height = max_height(pattern, x);
	fprintf(fd, "maxw: %d ---> maxh %d\n", width, height);
	pos = malloc(sizeof(int **) * nb_point(pattern, x));
	find_pos(pos, pattern, x);
	for (int i=0; i<nb_point(pattern, x); i++)
	{
		fprintf(fd, "x: %d", pos[i][0]);
		fprintf(fd, " y: %d\n", pos[i][1]);
	}
	place_piece(board, pos, height, width, p, nb_point(pattern, x));
}

// enregistrer tt les points de contacts exterieur pour pouvoir tester tout les positions
// avec en plus les coins importants !!!

// coord du x plus proche - coord pattern == result (x y)