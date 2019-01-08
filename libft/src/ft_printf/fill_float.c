/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_float.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 14:00:46 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:57:32 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char			*float2str(long double nb, int precision)
{
	char		*res;
	int			intpart;
	long double	decpart;

	if (precision == -1)
		precision = 6;
	nb = round_double(nb, precision);
	intpart = (int)nb;
	decpart = nb - intpart;
	res = ull_itoa(intpart, 10, 0);
	if (precision)
	{
		if (!(res = ft_strfjoin(res, ft_strdup("."))))
			return (NULL);
		if (!(res = ft_strfjoin(res, fill_decimal((long double)decpart,
		precision))))
			return (NULL);
	}
	return (res);
}

int				quit_float(long double nb, t_printf *list)
{
	char *str;

	if (list->param->max_field == 0 && (list->param->flags->plus == 0
	&& list->param->flags->blank == 0) && list->param->precision == -1)
	{
		if (nb < 0)
		{
			if (!(str = ft_strfjoin(ft_strdup("-"), float2str(nb,
			list->param->precision))))
				return (1);
		}
		else if (!(str = float2str(nb, list->param->precision)))
			return (1);
		list->content = str;
		return (1);
	}
	else if (!nb && list->param->precision == 0 && list->param->max_field == 0)
	{
		list->content = NULL;
		return (1);
	}
	return (0);
}

void			middle_float(t_params *param, char *str, int i, int nb)
{
	if (param->flags->zero == 1 && param->flags->minus == 0
	&& param->precision == -1)
	{
		ft_memset(str, '0', i);
		if (param->flags->plus == 1 && nb >= 0)
			str[0] = '+';
		else if (param->flags->blank == 1 && nb >= 0)
			str[0] = ' ';
		else if (nb < 0)
			str[0] = '-';
	}
	else
		ft_memset(str, ' ', i);
}

char			*float_quit(t_params *param, long double nb)
{
	char	*str;
	char	*numb;
	int		i;
	int		j;

	j = 0;
	if (!(numb = fill_float_prec(nb, param)))
		return (NULL);
	i = ((int)ft_strlen(numb) > param->max_field) ? (int)ft_strlen(numb)
	: param->max_field;
	if (param->precision == 0 && param->flags->hash == 1 && i !=
	(int)ft_strlen(numb))
		i--;
	if (!(str = ft_strnew(i)))
		return (NULL);
	middle_float(param, str, i, nb);
	i = (param->flags->minus == 1) ? 0 : i - ft_strlen(numb);
	while (j < (int)ft_strlen(numb) && (nb != 0 || param->precision != 0))
		str[i++] = numb[j++];
	if (param->flags->hash == 1 && ft_strchr(str, '.') == NULL)
		str = ft_strfjoin(str, ft_strdup("."));
	ft_strdel(&numb);
	return (str);
}

void			fill_float(t_printf *list, long double nb)
{
	char *ret;

	if (quit_float(nb, list) == 1)
		return ;
	else if (!(ret = float_quit(list->param, nb)))
		return ;
	list->content = ret;
}
