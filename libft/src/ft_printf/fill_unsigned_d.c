/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_unsigned_d.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 15:32:42 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:48:03 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		unsigned_length_if(t_params *param, int len)
{
	if ((param->flags->plus == 1 && param->max_field == 0)
	|| (param->flags->blank == 1)
	|| param->precision >= len)
		return (1);
	return (0);
}

char	*fill_unsigned_start_number(t_params *param)
{
	char *numb;

	if (!(numb = ft_strnew(1)))
		return (NULL);
	if (param->flags->plus == 1)
		numb[0] = '+';
	else if (param->type != 'u' && param->flags->blank == 1 &&
	(param->flags->zero == 0 || param->flags->minus == 1))
		numb[0] = ' ';
	return (numb);
}

char	*fill_unsigned_number(unsigned long long int nb, t_params *param)
{
	char	*prec;
	char	*numb;
	int		len;

	len = base_size(nb, 10);
	if (unsigned_length_if(param, len) == 1)
	{
		if (!(numb = fill_unsigned_start_number(param)))
			return (NULL);
		if (param->precision > 1)
		{
			if (!(prec = ft_strnew(param->precision - len)))
				return (NULL);
			ft_memset(prec, '0', param->precision - len);
			if (!(numb = ft_strfjoin(numb, prec)))
				return (NULL);
		}
		if (!(numb = ft_strfjoin(numb, ull_itoa(nb, 10, 0))))
			return (NULL);
	}
	else if (!(numb = ull_itoa(nb, 10, 0)))
		return (NULL);
	return (numb);
}

void	fill_unsigned_middle_d(t_printf *list, char *str, int i)
{
	if (list->param->flags->zero == 1 && list->param->flags->minus == 0 &&
	list->param->precision == -1)
		ft_memset(str, '0', i);
	else
		ft_memset(str, ' ', i);
}

void	fill_unsigned_d(t_printf *list, unsigned long long int nb)
{
	char	*str;
	char	*numb;
	int		i;
	int		j;

	if (!nb && list->param->precision == 0 && list->param->max_field == 0)
	{
		list->content = NULL;
		return ;
	}
	if (!(numb = fill_unsigned_number(nb, list->param)))
		return ;
	i = ((int)ft_strlen(numb) > list->param->max_field) ?
	(int)ft_strlen(numb) : list->param->max_field;
	if (!(str = ft_strnew(i)))
		return ;
	fill_unsigned_middle_d(list, str, i);
	i = (list->param->flags->minus == 1) ? 0 : i - ft_strlen(numb);
	j = 0;
	while (j < (int)ft_strlen(numb) && (nb != 0 ||
	list->param->precision != 0))
		str[i++] = numb[j++];
	ft_strdel(&numb);
	list->content = str;
}
