/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   floats_math.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 13:28:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:48:37 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long double		power(long double x, long double y)
{
	long double temp;

	if (y == 0)
		return (1);
	temp = power(x, y / 2);
	if ((int)y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}

long double		round_double(long double f, int i)
{
	f = f * power(10, i);
	f = (long double)(f + 0.5);
	return (f / power(10, i));
}

char			*fill_decimal(long double nb, int precision)
{
	char	*res;
	int		chr;
	int		i;

	chr = 0;
	i = 0;
	if (!(res = ft_strnew(precision)))
		return (0);
	while (i < precision)
	{
		nb *= 10;
		if (chr != 0)
			nb -= chr * 10;
		chr = (unsigned long long int)nb;
		res[i++] = chr + '0';
	}
	return (res);
}
