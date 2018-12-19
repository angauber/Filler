/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 21:27:32 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 07:07:27 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	fct_param_4(t_printf *parse, va_list list)
{
	if (parse->param->type == 'd' || parse->param->type == 'i')
		fill_digit(parse, va_arg(list, unsigned long long int));
	else if (parse->param->type == 'o')
		fill_octal(parse, va_arg(list, unsigned long long int));
	else if (parse->param->type == 'u')
		fill_unsigned_d(parse, va_arg(list, unsigned long long int));
	else if (parse->param->type == 'x')
		fill_hexa(parse, va_arg(list, unsigned long long int), 0);
	else if (parse->param->type == 'X')
		fill_hexa(parse, va_arg(list, unsigned long long int), 1);
}
