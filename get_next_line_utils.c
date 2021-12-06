/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:20:00 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/06 16:11:31 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strlcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	ft_strlcpy(dest + ft_strlen(dest), src);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;

	if (!s1)
	{
		s1 = malloc(1);
		*s1 = 0;
	}
	if (!s2)
		return (0);
	joined = malloc(sizeof(*joined) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == 0)
	{
		free(s1);
		free(s2);
		return (0);
	}
	joined[0] = 0;
	ft_strcat(joined, s1);
	ft_strcat(joined, s2);
}
