/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_float_bis.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 14:00:46 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:45:02 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_end_float(long double nb, t_params *param)
{
	char *numb;

	if (nb < 0 && param->flags->zero == 1 && param->flags->minus == 0
	&& param->precision == -1)
	{
		if (!(numb = float2str(nb * -1, param->precision)))
			return (NULL);
	}
	else if (nb < 0)
	{
		if (!(numb = ft_strfjoin(ft_strdup("-"), float2str(nb * -1,
		param->precision))))
			return (NULL);
	}
	else if (!(numb = float2str(nb, param->precision)))
		return (NULL);
	return (numb);
}

int		check_if(t_params *param, long double nb)
{
	if ((param->flags->plus == 1 && nb >= 0 && param->max_field == 0)
	|| (param->flags->blank == 1 && nb >= 0))
		return (1);
	return (0);
}

char	*fill_start_float(long double nb, t_params *param)
{
	char *numb;

	if (!(numb = ft_strnew(1)))
		return (NULL);
	if (param->flags->plus == 1 && nb >= 0)
		numb[0] = '+';
	else if (param->flags->blank == 1 && nb >= 0 && (param->flags->zero == 0
	|| param->flags->minus == 1))
		numb[0] = ' ';
	return (numb);
}

char	*fill_float_prec(long double nb, t_params *param)
{
	char	*numb;

	if (check_if(param, nb) == 1)
	{
		if (!(numb = ft_strfjoin(fill_start_float(nb, param),
		float2str(nb, param->precision))))
			return (NULL);
	}
	else if (!(numb = fill_end_float(nb, param)))
		return (NULL);
	return (numb);
}
