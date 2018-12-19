/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_string.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 16:06:25 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:52:16 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_string_bis(t_printf *list, char *base)
{
	char	*str;
	int		i;

	i = -1;
	if (!base)
		return (ft_strdup("(null)"));
	if (list->param->precision != -1 && list->param->precision <
	(int)ft_strlen(base))
	{
		if (!(str = ft_strnew(list->param->precision)))
			return (NULL);
		while (++i < list->param->precision)
			str[i] = base[i];
		return (str);
	}
	return (ft_strdup(base));
}

void	fill_string(t_printf *list, char *base)
{
	char	*bis;
	char	*str;
	int		i;
	int		j;

	if (!(bis = fill_string_bis(list, base)))
		return ;
	i = list->param->max_field;
	if ((int)ft_strlen(bis) > i)
		i = ft_strlen(bis);
	if (!(str = ft_strnew(i)))
		return ;
	ft_memset(str, ' ', i);
	i = ft_strlen(str) - ft_strlen(bis);
	if (list->param->flags->minus == 1)
		i = 0;
	j = 0;
	while (j < (int)ft_strlen(bis))
		str[i++] = bis[j++];
	ft_strdel(&bis);
	list->content = str;
}

void	fill_character(t_printf *list, char base)
{
	char	*str;
	int		i;

	i = list->param->max_field;
	if (!i)
		i = 1;
	if (!(str = ft_strnew(i)))
		return ;
	if (list->param->flags->zero == 1 && list->param->flags->minus == 0)
		ft_memset(str, '0', i);
	else
		ft_memset(str, ' ', i);
	if (!base)
		list->param->length = i;
	i = ft_strlen(str) - 1;
	if (list->param->flags->minus == 1)
		i = 0;
	str[i] = base;
	if (!base)
		list->param->flags->cnull = 1;
	list->content = str;
}
