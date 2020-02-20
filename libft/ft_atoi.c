/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:14:14 by phperrot          #+#    #+#             */
/*   Updated: 2019/11/14 16:11:44 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((char)str[i] == '\n' | (char)str[i] == '\r' | (char)str[i] == '\t'
			| (char)str[i] == '\f' | (char)str[i] == '\v' | (char)str[i] == ' ')
		i++;
	if ((char)str[i] == '+' && (char)str[i + 1] != '-')
		i++;
	if ((char)str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (((char)str[i] - '0') >= 0 && ('9' - (char)str[i]) >= 0)
	{
		nb = (nb * 10 + ((char)str[i] - '0'));
		i++;
	}
	return (nb * sign);
}
