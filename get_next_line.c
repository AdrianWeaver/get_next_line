/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:11:32 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/08 16:57:13 by aweaver          ###   ########.fr       */
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

	i = 0;
	while (memory[i] != 0 && memory[i] != '\n')
		i++;
	if (i < 0 && memory[i - 1] == '\n')
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
	line = malloc(sizeof(*line) * ft_strlen_custom(memory) + 1);
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
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(memory, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (fd == -1 || (bytes_read == 0 && !*memory))
		{
			return (0);
		}
		buffer[bytes_read] = 0;
		memory = ft_strjoin(memory, buffer);
	}
	line = ft_getline(memory);
	memory = ft_get_end(memory);
	if (ft_strchr(line, '\n') == 0)
		free(memory);
	return (line);
}

int	main(void)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open("toto.txt", O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
	{
		printf("le fichier n'a pas pu etre ouvert");
		return (0);
	}
	do{
		str = get_next_line(fd);
		printf("x%s", str);
		free(str);
		i++;
	} while (str);
	return (0);
}
