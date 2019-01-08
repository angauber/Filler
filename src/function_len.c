/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_len.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:53:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 18:08:56 by angauber    ###    #+. /#+    ###.fr     */
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
	while (++j < width)
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
		if (j == (int)ft_strlen(str[0]))
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
		while (++j < (int)ft_strlen(pattern[0]))
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
		while (++j < (int)ft_strlen(pattern[0]))
		{
			if (pattern[i][j] == '*')
				ctr++;
		}
	}
	return (ctr);
}

void	get_pattern(char **board, char **pattern, t_filler *filler)
{
	filler->piece->points = nb_point(pattern, filler->piece->height);
	filler->piece->width = max_width(pattern, filler->piece->height);
	filler->piece->height = max_height(pattern, filler->piece->height);
	if (!(filler->piece->coord = malloc(sizeof(int **) * filler->piece->points)))
		return ;
	find_pos(pattern, filler);
	place_piece(board, filler);
}
