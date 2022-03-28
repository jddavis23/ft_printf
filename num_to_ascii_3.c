/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:57:28 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/28 17:03:58 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_prcsion_round(long long unsigned int x,
	char **temp, t_flags *info, int option)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = ft_strnew(info->_precision);
	if (!str)
		return (NULL);
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < info->_precision)
		str[i++] = '0';
	ft_strrev(str, i);
	str[i] = '\0';
	ft_strcat(*temp, str);
	ft_strdel(&str);
	ft_rounder(temp, info, option);
	return (*temp);
}

static void	ft_option(long double nb, int *option)
{
	if (nb - (long long unsigned int)nb == 0.5)
		*option = 1;
	else if (nb - (long long unsigned int)nb > 0.5)
		*option = 2;
}

char	*ft_ftoa(t_flags *info, long double nb)
{
	char		*str;
	int			i;
	char		*temp;
	int			option;

	i = 0;
	str = NULL;
	option = 0;
	temp = ft_num_toa((long long unsigned int)nb, info, 10);
	if (!temp)
		return (NULL);
	if (info->_p_true && !info->_precision)
		return (temp);
	str = ft_strnew(ft_strlen(temp) + info->_precision + 2);
	ft_strcat(ft_strcat(str, temp), ".");
	ft_strdel(&temp);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	nb = (nb - (long long unsigned int)nb) * ft_power(10, info->_precision);
	ft_option(nb, &option);
	if (!ft_prcsion_round((long long unsigned int)nb, &str, info, option))
		return (NULL);
	return (str);
}