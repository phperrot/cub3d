/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:30:48 by phperrot          #+#    #+#             */
/*   Updated: 2019/12/21 14:24:32 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_fill_char(unsigned long n, char *s, int i, int negative)
{
	unsigned long	tmp;

	i--;
	if (negative)
		s[0] = '-';
	tmp = n;
	if (tmp >= 10)
	{
		ft_fill_char((tmp / 10), s, i, negative);
		s[i] = ((tmp % 10) + '0');
	}
	else
		s[i] = (tmp + '0');
	return (s);
}

static int			ft_size(unsigned long n, int negative)
{
	int				size;
	unsigned long	tmp;

	size = 0;
	if (negative)
		size++;
	tmp = n;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

char				*ft_itoa_long(long input)
{
	int				size;
	char			*number;
	int				negative;
	unsigned long	n;

	negative = (input < 0) ? 1 : 0;
	n = (input < 0) ? -input : input;
	if (!n)
		return (ft_strdup("0"));
	size = ft_size(n, negative);
	if (n == 0)
	{
		if (!(number = (char *)malloc(sizeof(*number) * 1)))
			return (NULL);
		number[0] = '0';
	}
	else
	{
		if (!(number = (char *)malloc(sizeof(*number) * size + 1)))
			return (NULL);
		number = ft_fill_char(n, number, size, negative);
	}
	number[size] = '\0';
	return (number);
}
