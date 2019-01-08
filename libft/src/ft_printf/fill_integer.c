/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_integer.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 15:32:42 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:46:35 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		quit_start(long long int nb, t_printf *list)
{
	if (list->param->max_field == 0 && (list->param->flags->plus == 0
	&& list->param->flags->blank == 0) && list->param->precision == -1)
	{
		if (nb < 0)
			list->content = ft_strfjoin(ft_strdup("-"),
			ull_itoa(nb * -1, 10, 0));
		else
			list->content = ull_itoa(nb, 10, 0);
		return (1);
	}
	else if (!nb && list->param->precision == 0 && list->param->max_field == 0)
	{
		list->content = NULL;
		return (1);
	}
	return (0);
}

void	middle_str(t_params *param, char *str, int i, int nb)
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

char	*fill_quit(t_params *param, long long int nb)
{
	char	*str;
	char	*numb;
	int		i;
	int		j;

	j = 0;
	if (!(numb = fill_number(nb, param)))
		return (NULL);
	i = ((int)ft_strlen(numb) > param->max_field) ? (int)ft_strlen(numb)
	: param->max_field;
	if (!(str = ft_strnew(i)))
		return (NULL);
	middle_str(param, str, i, nb);
	i = (param->flags->minus == 1) ? 0 : i - ft_strlen(numb);
	while (j < (int)ft_strlen(numb) && (nb != 0 || param->precision != 0))
		str[i++] = numb[j++];
	ft_strdel(&numb);
	return (str);
}

void	fill_digit(t_printf *list, long long int nb)
{
	char *str;

	if (quit_start(nb, list) == 1)
		return ;
	else
		str = fill_quit(list->param, nb);
	if (!str)
		return ;
	list->content = str;
}
