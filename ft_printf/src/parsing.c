/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 15:07:05 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:56:34 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_params	*init_params(void)
{
	t_params *param;

	if (!(param = (t_params *)malloc(sizeof(t_params))))
		return (NULL);
	param->type = 0;
	param->flags = init_flags();
	param->max_field = 0;
	param->precision = -1;
	param->modifier = 0;
	param->length = 0;
	return (param);
}

t_flags		*init_flags(void)
{
	t_flags *flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->blank = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->cnull = 0;
	return (flags);
}

void		check_flags(t_params *param, const char *str, int *x)
{
	*x += 1;
	while (str[*x] != '\0' && ft_strchr(FLAGS, str[*x]) != NULL)
	{
		if (str[*x] == '#')
			param->flags->hash = 1;
		else if (str[*x] == '0')
			param->flags->zero = 1;
		else if (str[*x] == '-')
			param->flags->minus = 1;
		else if (str[*x] == '+')
			param->flags->plus = 1;
		else if (str[*x] == ' ')
			param->flags->blank = 1;
		*x += 1;
	}
}

void		check_params(t_params *param, const char *str, int *x)
{
	while (str[*x] != '\0' && ft_strchr(TYPE, str[*x]) == NULL)
	{
		if (str[*x] >= '0' && str[*x] <= '9' && param->max_field == 0 &&
		param->precision == -1)
			param->max_field = ft_atoi(&str[*x]);
		else if (str[*x] == '.')
			param->precision = ft_atoi(&str[*x + 1]);
		*x += 1;
	}
	if (str[*x - 1] != '\0')
	{
		if (str[*x - 1] == 'h')
			param->modifier = 1;
		else if (str[*x - 1] == 'l')
			param->modifier = 3;
		else if (str[*x - 1] == 'L')
			param->modifier = 5;
		if (str[*x - 2] != '\0')
		{
			if (str[*x - 2] == 'h')
				param->modifier = 2;
			else if (str[*x - 2] == 'l')
				param->modifier = 4;
		}
	}
}

t_params	*find_params(const char *str, int *x)
{
	t_params	*param;

	if (!(param = init_params()))
		return (NULL);
	check_flags(param, str, x);
	check_params(param, str, x);
	if (str[*x] != '\0')
	{
		param->type = str[*x];
		*x += 1;
	}
	return (param);
}
