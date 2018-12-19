/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_octal.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 16:58:21 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:47:01 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_octal_bis(unsigned long long int nb, t_printf *list)
{
	char	*numb;

	if (list->param->precision >= base_size(nb, 8))
	{
		if (!(numb = ft_strnew(list->param->precision -
		base_size(nb, 8))))
			return (NULL);
		ft_memset(numb, '0', list->param->precision - base_size(nb, 8));
		if (!(numb = ft_strfjoin(numb, ull_itoa(nb, 8, 0))))
			return (NULL);
	}
	else
		numb = ull_itoa(nb, 8, 0);
	if (nb && list->param->flags->hash == 1 && list->param->precision <=
	base_size(nb, 8))
		numb = ft_strfjoin(ft_strdup("0"), numb);
	return (numb);
}

void	fill_middle_octal(t_printf *list, char *str, int i)
{
	if (list->param->flags->zero == 1 && list->param->flags->minus == 0
	&& list->param->precision == -1)
		ft_memset(str, '0', i);
	else
		ft_memset(str, ' ', i);
}

void	fill_octal(t_printf *list, unsigned long long int nb)
{
	int		i;
	int		j;
	char	*oct;
	char	*str;

	if (!nb && list->param->flags->hash == 0 && list->param->precision == 0 &&
	list->param->max_field == 0)
	{
		list->content = NULL;
		return ;
	}
	oct = fill_octal_bis(nb, list);
	i = ((int)ft_strlen(oct) > list->param->max_field)
	? (int)ft_strlen(oct) : list->param->max_field;
	str = ft_strnew(i);
	fill_middle_octal(list, str, i);
	i = (list->param->flags->minus == 1) ? 0 : i - ft_strlen(oct);
	j = 0;
	while (j < (int)ft_strlen(oct) && (nb != 0 || list->param->precision != 0 ||
	list->param->flags->hash == 1))
		str[i++] = oct[j++];
	ft_strdel(&oct);
	list->content = str;
}
