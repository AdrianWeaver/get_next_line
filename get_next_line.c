/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:11:32 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/07 15:50:25 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

#endif

int	ft_strlen_custom(char *memory)
{
	int	i;

	i = 1;
	while (memory[i] != 0 && memory[i] != '\n')
		i++;
	return (i);
}

void	*ft_get_end(char *memory)
{
	while (*memory && *memory != '\n')
		memory++;
	if (*memory == '\n')
		return (++memory);
	return (memory);
}

void	*ft_getline(char *memory)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(*line) * ft_strlen_custom(memory) + 2);
	if (line == 0)
		return (0);
	while (memory[i] != '\n' && memory[i + 1] != '\0')
	{
		line[i] = memory[i];
		i++;
	}
	line[i] = memory[i];
	i++;
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memory = "";
	char		*line;
	char		*buffer;
	int			bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(*buffer) *(BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	while (bytes_read > 0 && ft_strchr(memory, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		memory = ft_strjoin(memory, buffer);
	}
	line = ft_getline(memory);
	free(buffer);
	memory = ft_get_end(memory);
	return (line);
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;

	(void)ac;
	i = 0;
	fd = open(av[1], O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
	{
		printf("le fichier n'a pas pu etre ouvert");
		return (0);
	}
	while (i < 100)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return (0);
}
