/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:29:51 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/06 17:50:45 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*get_line(int fd, char *str, char *line)
{
	return (line);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;	

	if (!fd || fd >= 1024)
		return (0);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	line = get_line(fd, buffer, 
	buffer = ft_strjoin(buffer
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	open("./toto.txt", O_RDONLY);
	while (i < 5)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}
