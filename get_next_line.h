/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:50:34 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/08 11:45:46 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef FT_STRJOIN
#  define FT_STRJOIN

char	*ft_strjoin(char const *s1, char const *s2);

# endif
# ifndef FT_STRCHR
#  define FT_STRCHR

char	*ft_strchr(const char *s, int c);

# endif

# ifndef GET_NEXT_LINE
#  define GET_NEXT_LINE

char	*get_next_line(int fd);

# endif

# ifndef FT_STRLEN
#  define FT_STRLEN

int		ft_strlen(char *str);

# endif

# ifndef FT_STRCPY
#  define FT_STRCPY

char	*ft_strcpy(char *dest, char *src);

# endif
#endif
