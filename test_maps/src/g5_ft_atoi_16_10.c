/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g5_ft_atoi_16_10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:32:54 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 15:31:02 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_ox(char chr)
{
	if (chr >= '0' && chr <= '9')
		return (chr - '0');
	else if (chr >= 'A' && chr <= 'F')
		return (chr - 'A' + 10);
	else if (chr >= 'a' && chr <= 'f')
		return (chr - 'a' + 10);
	return (-1);
}

int			ft_atoi_16_10(const char *str)
{
	int		nbr;
	char	*str1;

	str1 = (char *)str + 2;
	nbr = 0;
	while (str1[0] != '\0' && str1[0] != ' ')
	{
		nbr = nbr * 16 + ft_ox(*str1);
		str1++;
	}
	return (nbr);
}
