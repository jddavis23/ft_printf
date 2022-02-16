/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_intdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:28:23 by molesen           #+#    #+#             */
/*   Updated: 2022/01/24 10:29:47 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_voiddel(void **arr, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		ft_memdel(&arr[i]);
		++i;
	}
	free(arr);
}