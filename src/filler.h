/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 10:57:17 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:31:54 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <stdlib.h>
# include "../ft_printf/include/ft_printf.h"

void	get_pattern(char **board, char **pattern, int x, FILE *fd, char p);
void	place_piece(char **board, int **pos, int height, int width, char p, int nb_point, int x);

#endif
