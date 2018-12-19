/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 14:02:20 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 17:53:52 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		free_list(t_printf **parse)
{
	t_printf *temp;
	t_printf *list;

	list = *parse;
	while (list)
	{
		temp = list->next;
		ft_strdel(&list->content);
		if (list->param)
		{
			free(list->param->flags);
			free(list->param);
		}
		free(list);
		list = temp;
	}
	*parse = NULL;
}

void		fill_list(t_printf **begin, char *content, t_params *param)
{
	t_printf *new_node;
	t_printf *last;

	last = *begin;
	if (!(new_node = (t_printf *)malloc(sizeof(t_printf))))
		return ;
	new_node->content = content;
	new_node->start = 0;
	new_node->param = param;
	new_node->next = NULL;
	if ((*begin)->start == 1)
	{
		free(*begin);
		*begin = new_node;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
}

t_printf	*init(const char *str)
{
	int			i;
	int			prev;
	t_printf	*list;

	if (!(list = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	list->next = NULL;
	list->start = 1;
	i = 0;
	while (str[i] != '\0')
	{
		prev = i;
		while (str[i] != '%' && str[i] != '\0')
			i++;
		if (i != prev)
			fill_list(&list, ft_strsub(str, prev, i - prev), NULL);
		else
			fill_list(&list, NULL, find_params(str, &i));
	}
	return (list);
}

int			printf_output(va_list list, t_printf *parse)
{
	int			length;

	length = 0;
	while (parse != NULL)
	{
		if (parse->content == NULL)
			fct_pointer_type(parse, list);
		if (parse->param && parse->param->flags->cnull == 1)
		{
			length += parse->param->length;
			ft_putlentgh(parse->content, parse->param->length);
		}
		else
		{
			if (parse->content)
			{
				length += (int)ft_strlen(parse->content);
				ft_putstr(parse->content);
			}
		}
		parse = parse->next;
	}
	return (length);
}

int			ft_printf(const char *str, ...)
{
	t_printf	*parse;
	va_list		list;
	int			ret;

	if (!str[0])
		return (0);
	if (!(parse = init(str)))
		return (-1);
	va_start(list, str);
	ret = printf_output(list, parse);
	va_end(list);
	free_list(&parse);
	return (ret);
}
