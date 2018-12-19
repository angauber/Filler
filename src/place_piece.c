/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 17:24:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:54:20 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		place_piece()
{

}

int		find_coord(char **coord, int x, char p, int **pos, int width, int height)
{
	int i;
	int j;

	i = x;
	while (i >= x)
	{
		j = ft_strlen(coord[0]);
		while (j >= ft_strlen(coord[0]))
		{
			if (coord[i][j] == 'p')
			{
				if (place_piece(pos, width, height) == 0)
					return (0);
			}
			j--;
		}
		i--;
	}
	return (1);
}

void	place_piece(char **board, int **pos, int height, int width, char p, int nb_point, int x)
{
	int i;

	i = 0;
	while (i == 0)
		i = find_coord(board, x, p, pos); 
}