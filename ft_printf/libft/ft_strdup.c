/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:47:07 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 11:21:06 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	i = ft_strlen(s);
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	dst[i] = '\0';
	i--;
	while (i >= 0)
	{
		dst[i] = s[i];
		i--;
	}
	return (dst);
}
