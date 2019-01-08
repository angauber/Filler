/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ull_itoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 14:32:36 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:49:23 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		base_size(unsigned long long int nb, int base)
{
	int ret;

	ret = 0;
	if (nb == 0)
		ret++;
	while (nb != 0)
	{
		ret++;
		nb /= base;
	}
	return (ret);
}

int		llbase_size(long long int nb)
{
	int ret;

	ret = 0;
	if (nb <= 0)
		ret++;
	while (nb != 0)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

char	*ull_itoa(unsigned long long int nb, int base, int maj)
{
	int		len;
	char	*str;
	char	c;

	len = base_size(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		if (base == 16 && nb % 16 > 9)
			c = (maj == 1) ? nb % 16 + 55 : nb % 16 + 87;
		else
			c = nb % base + '0';
		str[len] = c;
		nb /= base;
	}
	return (str);
}
