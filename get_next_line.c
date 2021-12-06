/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:11:32 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/06 16:26:21 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../../holy1/libft/libft.h"
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096

#endif

char	*ft_make_magic(char *buffer, int fd, int index)
{
	int		letters_read;
	char	*line;
	char	*temp;

	temp = ft_strdup(line);
	letters_read = 1;
	if (letters_read != 0 && (ft_strchr(buffer, '\n') != 0))
	{
		letters_read = read(fd, buffer, BUFFER_SIZE);
		buffer[letters_read] = 0;
	}
	line = ft_strjoin(buffer, 
	index += letters_read;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = "";
	int			index;

	if (fd == -1 || fd >= 1024)
		return (0);
	index = 0;
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	ft_make_magic(buffer, fd, index);
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
	{
		printf("le fichier n'a pas pu etre ouvert");
		return (0);
	}
	printf("ft_get_next_line renvoie : %s\n", get_next_line(fd));
	return (0);
}
