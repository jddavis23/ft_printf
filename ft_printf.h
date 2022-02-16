/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:36:17 by jdavis            #+#    #+#             */
/*   Updated: 2022/02/16 11:30:48 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		_space;
	int		_zero;
	int		_plus;
	int		_hash;
	int		_minus;
	t_width	*next;
}				t_flags;

typedef struct s_width
{
	int			_width;
	t_precision	*next;
}				t_width;

typedef struct s_precision
{
	int			_precision;
	t_length	*next;
}				t_precision;

typedef struct s_length
{
	int	_hh;
	int	_h;
	int	_ll;
	int	_l;
}				t_length;

#endif