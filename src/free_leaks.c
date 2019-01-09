/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_leaks.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 17:28:28 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 17:47:24 by angauber    ###    #+. /#+    ###.fr     */
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

void	free_struct(t_filler *filler)
{
	free(filler->piece);
	free(filler);
}
