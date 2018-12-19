/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_integer_bis.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 12:12:21 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 14:26:48 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_end_number(long long int nb, t_params *param)
{
	char *numb;

	if (nb < 0 && param->flags->zero == 1 && param->flags->minus == 0
	&& param->precision == -1)
	{
		if (!(numb = ull_itoa(nb * -1, 10, 0)))
			return (NULL);
	}
	else if (nb < 0)
	{
		if (!(numb = ft_strfjoin(ft_strdup("-"), ull_itoa(nb * -1, 10, 0))))
			return (NULL);
	}
	else
	{
		if (!(numb = ull_itoa(nb, 10, 0)))
			return (NULL);
	}
	return (numb);
}

int		length_if(t_params *param, long long int nb, int len)
{
	if ((param->flags->plus == 1 && nb >= 0 && param->max_field == 0)
	|| (param->flags->blank == 1 && nb >= 0)
	|| param->precision >= len)
		return (1);
	return (0);
}

char	*fill_start_number(long long int nb, t_params *param)
{
	char *numb;

	numb = NULL;
	if (param->flags->plus == 1 && nb >= 0)
	{
		if (!(numb = ft_strnew(1)))
			return (NULL);
		numb[0] = '+';
	}
	else if (param->type != 'u' && param->flags->blank == 1 && nb >= 0 &&
	(param->flags->zero == 0 || param->flags->minus == 1))
	{
		if (!(numb = ft_strnew(1)))
			return (NULL);
		numb[0] = ' ';
	}
	return (numb);
}

char	*fill_number(long long int nb, t_params *param)
{
	char	*prec;
	char	*numb;
	int		len;
	int		spe;

	spe = (nb < 0) ? 1 : 0;
	len = (nb < 0) ? base_size(nb * -1, 10) : base_size(nb, 10);
	if (length_if(param, nb, len) == 1)
	{
		numb = fill_start_number(nb, param);
		if (param->precision > 1)
		{
			if (nb < 0 && param->precision != -1)
				nb *= -1;
			prec = ft_strnew(param->precision - len + spe);
			ft_memset(prec, '0', param->precision - len + spe);
			numb = ft_strfjoin(numb, prec);
			numb[0] = (spe == 1) ? '-' : numb[0];
		}
		numb = (nb < 0 && !numb) ? ft_strfjoin(ft_strdup("-"), ull_itoa(nb * -1
		, 10, 0)) : ft_strfjoin(numb, ull_itoa(nb, 10, 0));
	}
	else
		numb = fill_end_number(nb, param);
	return (numb);
}
