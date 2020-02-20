/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:04:12 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 17:04:15 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin_free(char const *s1, char const *s2, int param)
{
	size_t			len;
	char			*out;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(out = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(out, s1, ft_strlen((char*)s1) + 1);
	ft_strlcat(out, s2, len);
	if (param == 1 || param == 3)
	{
		free((char*)s1);
		s1 = NULL;
	}
	if (param == 2 || param == 3)
	{
		free((char *)s2);
		s2 = NULL;
	}
	return (out);
}
