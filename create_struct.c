/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:28:56 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/22 16:33:55 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_create_struct(t_flags *in_flags)
{
	if (!in_flags)
	{
		in_flags = (t_flags *) malloc(sizeof(t_flags));
		if (!in_flags)
			return (NULL);
		in_flags->_ret = 0;
	}
	in_flags->_space = 0;
	in_flags->_zero = 0;
	in_flags->_minus = 0;
	in_flags->_plus = 0;
	in_flags->_hash = 0;
	in_flags->_h_sub = 0;
	in_flags->_div = 0;
	in_flags->_width = 0;
	in_flags->_precision = 0;
	in_flags->_p_true = 0;
	in_flags->_p_check = 0;
	in_flags->_hh = 0;
	in_flags->_h = 0;
	in_flags->_ll = 0;
	in_flags->_l = 0;
	in_flags->_L = 0;
	return (in_flags);
}

int	ft_is_type(char c)
{
	if (c != 'd' && c != 'i' && c != 'o'
		&& c != 'u' && c != 'x' && c != 'X'
		&& c != 'c' && c != 's' && c != 'p'
		&& c != 'f' && c != '%')
		return (1);
	return (-1);
}
