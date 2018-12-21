/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   real_reading.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 14:11:52 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 14:16:22 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "src/filler.h"

int		main()
{
	char	*str;
	FILE	*fd;

	fd = fopen("log", "w");
	while (get_next_line(0, &str) != 0)
	{
		fprintf(fd, "%s\n", str);
	}
	return (0);
}