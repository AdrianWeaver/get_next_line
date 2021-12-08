/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:08 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/08 11:44:58 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{	
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_joined;

	if (!s1 || !s2)
		return (0);
	str_joined = malloc(sizeof(*str_joined) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (str_joined == 0)
		return (0);
	str_joined[0] = 0;
	ft_strcat(str_joined, s1);
	ft_strcat(str_joined, s2);
	return (str_joined);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c >= 256)
		c %= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}
