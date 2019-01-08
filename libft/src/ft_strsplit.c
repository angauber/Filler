/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:49:22 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 18:26:02 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_strfill(int ctr, int c, const char *s, char **str)
{
	int i;
	int start;
	int len;
	int k;

	i = 0;
	k = 0;
	while (ctr >= 0)
	{
		while (s[i] == c)
			i++;
		start = i;
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (!(str[k] = ft_strsub(s, start, len)))
			return (NULL);
		k++;
		ctr--;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		ctr;
	char	**str;

	if (!s | !c)
		return (NULL);
	ctr = ft_count_words(s, c);
	if (!(str = malloc(sizeof(char *) * (ctr + 1))))
		return (NULL);
	str[ctr] = (char *)'\0';
	ctr--;
	return (ft_split_strfill(ctr, c, s, str));
}
