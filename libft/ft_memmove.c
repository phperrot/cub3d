/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:54:49 by phperrot          #+#    #+#             */
/*   Updated: 2019/11/14 15:42:49 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	if (len == 0)
		return (dst);
	if ((src == NULL && dst == NULL))
		return (NULL);
	i = 0;
	len = len - 1;
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	if (tmp1 < tmp2)
		while ((int)(len) >= 0)
		{
			*(tmp2 + len) = *(tmp1 + len);
			len--;
		}
	else
		while (i <= len)
		{
			*(tmp2 + i) = *(tmp1 + i);
			i++;
		}
	return (dst);
}
