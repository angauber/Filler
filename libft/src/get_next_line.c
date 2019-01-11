/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 13:55:54 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 17:55:05 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	return_value(char *tmp, int ret)
{
	if (!*tmp && ret == 0)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

static int	fill_line(char **line, char *tmp, char *str[10240], int fd)
{
	int		i;
	char	*tmpp;

	i = ft_strcharlen(tmp, '\n');
	if (!(*line = ft_strsub(tmp, 0, i)))
		return (-1);
	tmpp = str[fd];
	if (!(str[fd] = ft_strsub(tmp, (i + 1), (ft_strlen(tmp) - i))))
		return (-1);
	ft_strdel(&tmpp);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str[10240];
	char			buf[BUFF_SIZE + 1];
	char			*frd;
	char			*tmp;
	int				ret;

	if (fd < 0 || fd >= 10240 || !line || BUFF_SIZE < 1 ||
	read(fd, buf, 0) == -1 || (!str[fd] && (!(tmp = ft_strnew(0)))))
		return (-1);
	if (str[fd])
		tmp = ft_strdup(str[fd]);
	while (!(ft_strchr(tmp, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		frd = tmp;
		tmp = ft_strjoin(frd, buf);
		ft_strdel(&frd);
	}
	if (fill_line(line, tmp, str, fd) == -1)
		return (-1);
	return (return_value(tmp, ret));
}
