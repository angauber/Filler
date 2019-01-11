/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_leaks.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 17:28:28 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 12:20:33 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	free_2d_tab(char **tab, int i)
{
	int x;

	x = -1;
	while (++x < i)
		ft_strdel(&tab[x]);
}

void	free_2d_int_tab(int **tab, int i)
{
	int x;

	x = -1;
	while (++x < i)
	{
		free(tab[x]);
		tab[x] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	free_struct(t_filler *filler, char **board)
{
	free(filler->piece);
	free(filler);
	free(board);
}

void	change_best(int *pos, int *bestpos)
{
	bestpos[0] = pos[0];
	bestpos[1] = pos[1];
}
