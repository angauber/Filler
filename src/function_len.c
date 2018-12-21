/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_len.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:53:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 15:46:16 by angauber    ###    #+. /#+    ###.fr     */
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

void	find_pos(char **pattern, t_filler *filler)
{
	int i;
	int j;
	int z;

	i = 0;
	z = 0;
	while (z < filler->piece->points)
	{
		j = -1;
		while (++j < ft_strlen(pattern[0]))
		{
			if (pattern[i][j] == '*')
			{
				filler->piece->coord[z] = malloc(sizeof(int *) * 2);
				filler->piece->coord[z][0] = i;
				filler->piece->coord[z][1] = j;
				z++;
			}
		}
		i++;
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

void	print_filler(t_filler *filler, int fd)
{
	dprintf(fd, "____ReCaP FiLlEr____\n\n\nplayer : %c\n", filler->player);
	dprintf(fd, "board_width: %d board_height: %d\n", filler->board_width, filler->board_height);
	dprintf(fd, "\n\n___PIECE___\nwidth %d height: %d\npoints: %d\n", filler->piece->width, filler->piece->height, filler->piece->points);
}

void	get_pattern(char **board, char **pattern, int fd, t_filler *filler)
{
	filler->piece->points = nb_point(pattern, filler->piece->height);
	filler->piece->width = max_width(pattern, filler->piece->height);
	filler->piece->height = max_height(pattern, filler->piece->height);
	filler->piece->coord = malloc(sizeof(int **) * filler->piece->points);
	find_pos(pattern, filler);
	for (int i=0; i<filler->piece->points; i++)
	{
		dprintf(fd, "x: %d", filler->piece->coord[i][0]);
		dprintf(fd, " y: %d\n", filler->piece->coord[i][1]);
	}
	print_filler(filler, fd);
	place_piece(board, filler, fd);
}

// enregistrer tt les points de contacts exterieur pour pouvoir tester tout les positions
// avec en plus les coins importants !!!

// coord du x plus proche - coord pattern == result (x y)
