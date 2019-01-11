/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   try.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:28:16 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 17:39:07 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../src/filler.h"

int		main()
{
	char *line;

	while (get_next_line(0, &line) != 0)
	{
		ft_printf("line: %s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}