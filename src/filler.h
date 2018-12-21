/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:57:17 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 14:54:47 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <stdlib.h>
# include "../ft_printf/include/ft_printf.h"

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
	struct s_piece	*piece;
}					t_filler;

void	get_pattern(char **board, char **pattern, int fd, t_filler *filler);
void	place_piece(char **board, t_filler *filler, int fd);

#endif
