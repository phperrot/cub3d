/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:24:17 by phperrot          #+#    #+#             */
/*   Updated: 2019/11/19 11:46:30 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*output;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	output = (char *)malloc(sizeof(*output) * len + 1);
	if (output == NULL)
		return (NULL);
	while (len)
	{
		output[i] = s[start];
		start++;
		i++;
		len--;
	}
	output[i] = '\0';
	return (output);
}
