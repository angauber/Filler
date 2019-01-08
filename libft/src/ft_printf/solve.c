/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 15:16:23 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 14:30:23 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	fct_param_0(t_printf *parse, va_list list)
{
	if (parse->param->type == '%')
		fill_character(parse, '%');
	else if (parse->param->type == 'c')
		fill_character(parse, va_arg(list, int));
	else if (parse->param->type == 's')
		fill_string(parse, va_arg(list, char *));
	else if (parse->param->type == 'p')
		fill_address(parse, (unsigned long int)va_arg(list, void *));
	else if (parse->param->type == 'd' || parse->param->type == 'i')
		fill_digit(parse, va_arg(list, int));
	else if (parse->param->type == 'o')
		fill_octal(parse, (unsigned long long int)va_arg(list, unsigned int));
	else if (parse->param->type == 'u')
		fill_unsigned_d(parse, va_arg(list, unsigned int));
	else if (parse->param->type == 'x')
		fill_hexa(parse, va_arg(list, unsigned int), 0);
	else if (parse->param->type == 'X')
		fill_hexa(parse, va_arg(list, unsigned int), 1);
	else if (parse->param->type == 'f')
		fill_float(parse, va_arg(list, double));
}

void	fct_param_1(t_printf *parse, va_list list)
{
	if (parse->param->type == 'd' || parse->param->type == 'i')
		fill_digit(parse, (short int)va_arg(list, int));
	else if (parse->param->type == 'o')
		fill_octal(parse, (short int)va_arg(list, int));
	else if (parse->param->type == 'u')
		fill_unsigned_d(parse, (unsigned short)va_arg(list, unsigned int));
	else if (parse->param->type == 'x')
		fill_hexa(parse, (short int)va_arg(list, int), 0);
	else if (parse->param->type == 'X')
		fill_hexa(parse, (short int)va_arg(list, int), 1);
}

void	fct_param_2(t_printf *parse, va_list list)
{
	if (parse->param->type == 'd' || parse->param->type == 'i')
		fill_digit(parse, (char)va_arg(list, int));
	else if (parse->param->type == 'o')
		fill_octal(parse, (unsigned char)va_arg(list, int));
	else if (parse->param->type == 'u')
		fill_unsigned_d(parse, (unsigned char)va_arg(list, unsigned int));
	else if (parse->param->type == 'x')
		fill_hexa(parse, (unsigned char)va_arg(list, int), 0);
	else if (parse->param->type == 'X')
		fill_hexa(parse, (unsigned char)va_arg(list, int), 1);
}

void	fct_param_3(t_printf *parse, va_list list)
{
	if (parse->param->type == 'd' || parse->param->type == 'i')
		fill_digit(parse, va_arg(list, unsigned long int));
	else if (parse->param->type == 'f')
		fill_float(parse, va_arg(list, double));
	else if (parse->param->type == 'o')
		fill_octal(parse, va_arg(list, unsigned long int));
	else if (parse->param->type == 'u')
		fill_unsigned_d(parse, va_arg(list, unsigned long int));
	else if (parse->param->type == 'x')
		fill_hexa(parse, va_arg(list, unsigned long int), 0);
	else if (parse->param->type == 'X')
		fill_hexa(parse, va_arg(list, unsigned long int), 1);
}

void	fct_pointer_type(t_printf *parse, va_list list)
{
	if (parse->param->modifier == 0)
		fct_param_0(parse, list);
	else if (parse->param->modifier == 1)
		fct_param_1(parse, list);
	else if (parse->param->modifier == 2)
		fct_param_2(parse, list);
	else if (parse->param->modifier == 3)
		fct_param_3(parse, list);
	else if (parse->param->modifier == 4)
		fct_param_4(parse, list);
	else if (parse->param->modifier == 5)
	{
		if (parse->param->type == 'f')
			fill_float(parse, va_arg(list, long double));
	}
}
