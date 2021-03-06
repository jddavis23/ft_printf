/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:31:58 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/15 16:41:48 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Applying 0x or 0 to hex or oct values if "#" is applied to type specifier.
 * 
 * Function is used in ft_solve_signed.
 */

void	ft_apply_hash(t_flags *info, unsigned int nb, char **temp, int *i)
{
	if (info->_hash && ((!info->_p_check && nb != 0) || (info->_type != 'o' \
		&& nb != 0) || (nb == 0 && info->_type == 'o' && info->_p_check && \
		!info->_precision)) && (info->_type == 'X' || info->_type == 'x' || \
		info->_type == 'u' || info->_type == 'o'))
	{
		ft_strcpy(&(*temp)[*i], info->_h_prfx);
		*i += ft_strlen(info->_h_prfx);
	}
}

/*
 * Dynamically allocating memory for the precision applied string.
 *
 * Due to the "-" char id a number is negative, precision is stil applied 
 * if the incoming string is the same length as the precision value. 
 */

static char	*ft_if_helper_i(t_flags *info, char **temp, long long int nb)
{
	if (nb < 0)
		*temp = ft_strnew(info->_precision + 1);
	else
		*temp = ft_strnew(info->_precision);
	return (*temp);
}

/*
 * If the number is zero, an empty string is created.
 */

static int	ft_else_helper(char **str)
{
	ft_strdel(str);
	*str = ft_strnew(0);
	return (1);
}

static char	*ft_if_helper_ii(t_flags *info, char *temp, char *str, int *i)
{
	while (*i < (info->_precision - (int)ft_strlen(str) + 2))
		temp[(*i)++] = '0';
	ft_strcpy(&(temp)[*i], &str[1]);
	return (temp);
}

/*
 * Applying precision to both signed and unsigned int arguments.
 *
 * Precision is applied if the length of string (holding int value) is 
 * less than precision value.
 */

int	ft_precision_nb(t_flags *info, char **str, long long int nb)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (info->_precision > (int)ft_strlen(*str)
		|| (nb < 0 && (int)ft_strlen(*str) == info->_precision))
	{
		if (!ft_if_helper_i(info, &temp, nb))
			return (-1);
		if (nb < 0)
			temp[i++] = '-';
		while (i < (info->_precision - (int)ft_strlen(*str)))
			temp[i++] = '0';
		if (nb < 0)
			temp = ft_if_helper_ii(info, temp, *str, &i);
		else
			ft_strcpy(&temp[i], *str);
		ft_strdel(str);
		*str = temp;
		return (1);
	}
	else if (!info->_precision && info->_p_true && nb == 0)
		return (ft_else_helper(str));
	return (0);
}
