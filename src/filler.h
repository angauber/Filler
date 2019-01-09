/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:57:17 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 17:34:09 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/ft_printf.h"

typedef struct		s_piece
{
	int				width;
	int				height;
	int				points;
	int				**coord;
}					t_piece;

typedef struct		s_filler
{
	char			player;
	int				board_width;
	int				board_height;
	int				start_h;
	int				start_w;
	struct s_piece	*piece;
}					t_filler;

void	get_pattern(char **board, char **pattern, t_filler *filler);
void	place_piece(char **board, t_filler *filler);

void	recursive_heat(int **map, t_filler *filler);
int		**create_heat_map(char **board, t_filler *filler);

int		check_placable_piece(char **board, int i, int j, t_filler *filler, int *pos);
int		free_height(t_piece *piece);
int		free_width(t_piece *piece);

void	free_struct(t_filler *filler);
void	free_2d_tab(char **tab, int i);
void	free_2d_int_tab(int **tab, int i);

#endif
