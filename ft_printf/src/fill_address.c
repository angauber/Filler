/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_address.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 15:21:03 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 13:57:50 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	fill_address(t_printf *list, unsigned long nb)
{
	char	*str;
	char	*numb;
	int		i;
	int		j;

	if (!(numb = ft_strfjoin(ft_strdup("0x"), ull_itoa(nb, 16, 0))))
		return ;
	i = list->param->max_field;
	if ((int)ft_strlen(numb) > i)
		i = ft_strlen(numb);
	if (!(str = ft_strnew(i)))
		return ;
	ft_memset(str, ' ', i);
	i -= ft_strlen(numb);
	j = 0;
	if (list->param->flags->minus == 1)
		i = 0;
	while (j < (int)ft_strlen(numb))
		str[i++] = numb[j++];
	ft_strdel(&numb);
	list->content = str;
}
