/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 09:45:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 13:48:22 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*concat;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(concat = malloc(sizeof(char) * len + 1)))
		return (NULL);
	concat[len] = '\0';
	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		concat[i++] = s2[j++];
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (concat);
}
