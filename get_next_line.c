/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:11:32 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/09 11:32:34 by aweaver          ###   ########.fr       */
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
	if (*memory == 0)
		return (0);
	while (memory[i] != 0 && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	return (i);
}

void	*ft_get_end(char *memory)
{
	if (*memory == 0)
		return (memory);
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
	while (memory[i] != '\n' && memory[i] != '\0')
	{
		line[i] = memory[i];
		i++;
	}
	line[i] = memory[i];
	if (line[i] == '\n')
	{
		i++;
		line[i] = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	memory[BUFFER_SIZE + 1] = "";
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(memory, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((bytes_read == -1 || (bytes_read == 0 && !*memory)))
			return (0);
		buffer[bytes_read] = 0;
		ft_strcat(memory, buffer);
	}
	line = ft_getline(memory);
	ft_strcpy(memory, ft_get_end(memory));
	return (line);
}

//int	main(void)
//{
	//int		i;
	//int		fd;
	//char	*str;
//
	//i = 0;
	//fd = open("illiade.txt", O_RDONLY);
	//printf("%d\n", fd);
	//if (fd == -1)
	//{
		//printf("le fichier n'a pas pu etre ouvert");
		//return (0);
	//}
	//do{
		//str = get_next_line(fd);
		//printf("x%s", str);
		//free(str);
		//i++;
	//} while (str);
	//return (0);
//}
