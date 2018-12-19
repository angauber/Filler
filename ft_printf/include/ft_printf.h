/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 11:39:02 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 12:51:18 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPE "%cspdiouxXf"
# define FLAGS "#0-+ "

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int				hash;
	int				plus;
	int				minus;
	int				zero;
	int				blank;
	int				cnull;
}					t_flags;

typedef struct		s_params
{
	int				type;
	int				precision;
	int				max_field;
	int				modifier;
	int				length;
	struct s_flags	*flags;
}					t_params;

typedef struct		s_printf
{
	char			*content;
	int				start;
	struct s_params *param;
	struct s_printf	*next;
}					t_printf;

t_params			*find_params(const char *str, int *x);
t_params			*init_params(void);
t_flags				*init_flags(void);

int					ft_printf(const char *str, ...);

int					base_size(unsigned long long int nb, int base);
int					llbase_size(long long int nb);

char				*ull_itoa(unsigned long long int nb, int base, int maj);
char				*ll_itoa(long long int nb);
char				*fill_number(long long int nb, t_params *param);
char				*fill_string_bis(t_printf *list, char *base);
char				*fill_float_prec(long double nb, t_params *param);
char				*float2str(long double nb, int sn);
char				*fill_decimal(long double nb, int precision);

void				fill_address(t_printf *list, unsigned long nb);
void				fct_pointer_type(t_printf *parse, va_list list);
void				fill_digit(t_printf *list, long long int nb);
void				fill_string(t_printf *list, char *base);
void				fill_character(t_printf *list, char base);
void				fill_address(t_printf *list, unsigned long nb);
void				fill_hexa(t_printf *list,
					unsigned long long int nb, int maj);
void				fill_octal(t_printf *list, unsigned long long int nb);
void				fill_unsigned_d(t_printf *list, unsigned long long int nb);
void				fill_float(t_printf *list, long double nb);

long double			power(long double x, long double y);
long double			round_double(long double f, int i);

void				fct_param_4(t_printf *parse, va_list list);

#endif
