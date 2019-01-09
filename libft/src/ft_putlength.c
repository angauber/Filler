/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putlength.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 14:17:10 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 14:17:48 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlentgh(char *str, int i)
{
	int j;

	j = -1;
	while (++j < i)
		ft_putchar(str[j]);
}