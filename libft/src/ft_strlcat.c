/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:59:56 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 11:29:07 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t s_dst;
	size_t s_src;

	i = 0;
	s_dst = ft_strlen(dst);
	s_src = ft_strlen(src);
	if (size == 0)
		return (s_src);
	if (size <= s_dst)
		return (s_src + size);
	while ((src[i] != '\0') && (s_dst + i < size - 1))
	{
		dst[s_dst + i] = src[i];
		i++;
	}
	dst[s_dst + i] = '\0';
	return (s_src + s_dst);
}
