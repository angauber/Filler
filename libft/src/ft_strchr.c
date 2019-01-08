/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:14:21 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 18:53:31 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t x;
	size_t len;

	x = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (s[x])
	{
		if (s[x] == c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}
