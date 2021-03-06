/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_piece.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:53:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 12:00:54 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

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
	if (!(filler->piece->coord = malloc(sizeof(int *) * filler->piece->points)))
		return ;
	find_pos(pattern, filler);
	place_piece(board, filler);
	free_2d_int_tab(filler->piece->coord, filler->piece->points);
}
