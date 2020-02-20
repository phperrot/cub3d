/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:43:57 by phperrot          #+#    #+#             */
/*   Updated: 2019/11/14 16:10:44 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*small;
	char	*large;
	size_t	i;

	small = (char*)needle;
	large = (char*)haystack;
	if (*small == '\0')
		return (large);
	i = ft_strlen(small);
	while (*large && len-- >= i)
	{
		if (ft_memcmp(large, small, i) == 0)
			return (large);
		large++;
	}
	return (NULL);
}
