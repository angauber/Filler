/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:35:09 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 17:37:04 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "src/filler.h"

int main()
{
	char *line;

	while (get_next_line(0, &line))
	{
		ft_printf("%s", line);
	}
}