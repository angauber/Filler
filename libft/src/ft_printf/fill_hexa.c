/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_hexa.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:18:43 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 14:16:08 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_hexa_bis(unsigned long long int nb, t_printf *list, int maj)
{
	char	*numb;

	if (list->param->precision >= base_size(nb, 16))
	{
		if (!(numb = ft_strnew(list->param->precision -
		base_size(nb, 16))))
			return (NULL);
		ft_memset(numb, '0', list->param->precision - base_size(nb, 16));
		if (!(numb = ft_strfjoin(numb, ull_itoa(nb, 16, maj))))
			return (NULL);
	}
	else if (!(numb = ull_itoa(nb, 16, maj)))
		return (NULL);
	if (nb && list->param->flags->hash == 1 && (list->param->flags->zero == 0
	|| list->param->precision == 0))
		return ((maj == 1) ? ft_strfjoin(ft_strdup("0X"), numb) :
		ft_strfjoin(ft_strdup("0x"), numb));
	else
		return (numb);
}

char	*fill_middle_hexa(char *hex, t_printf *list, int nb, int *i)
{
	char	*str;

	*i = ((int)ft_strlen(hex) > list->param->max_field)
	? (int)ft_strlen(hex) : list->param->max_field;
	if (nb && *i > 2 && list->param->flags->hash == 1 &&
	list->param->flags->zero
	== 1 && list->param->precision == -1)
		*i -= 2;
	if (!(str = ft_strnew(*i)))
		return (NULL);
	if (list->param->flags->zero == 1 && list->param->flags->minus == 0
	&& list->param->precision == -1)
		ft_memset(str, '0', *i);
	else
		ft_memset(str, ' ', *i);
	return (str);
}

void	fill_hexa(t_printf *list, unsigned long long int nb, int maj)
{
	int		i;
	int		j;
	char	*hex;
	char	*str;

	if (!nb && list->param->precision == 0 && list->param->max_field == 0)
	{
		list->content = NULL;
		return ;
	}
	if (!(hex = fill_hexa_bis(nb, list, maj)))
		return ;
	if (!(str = fill_middle_hexa(hex, list, nb, &i)))
		return ;
	i = (list->param->flags->minus == 1) ? 0 : i - ft_strlen(hex);
	j = 0;
	while (j < (int)ft_strlen(hex) && (nb != 0 || list->param->precision != 0))
		str[i++] = hex[j++];
	if (nb && list->param->flags->hash == 1 && list->param->flags->zero == 1 &&
	list->param->precision != 0)
		str = (maj == 1) ? ft_strfjoin(ft_strdup("0X"), str) :
		ft_strfjoin(ft_strdup("0x"), str);
	ft_strdel(&hex);
	list->content = str;
}
