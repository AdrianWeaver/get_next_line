/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:11:32 by aweaver           #+#    #+#             */
/*   Updated: 2021/12/07 12:09:52 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../../holy1/libft/libft.h"
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
	return (i);
}

void	*ft_getline(char *memory)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(*line) * ft_strlen_custom(memory) + 1);
	if (line == 0)
		return (0);
	while (memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memory = "";
	char		*line;
	char		*buffer;
	int			bytes_read;

	buffer = malloc(sizeof(*buffer) *(BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		memory = ft_strjoin(memory, buffer);
	}
	line = ft_getline(memory);
	free(buffer);
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
	printf("ft_get_next_line renvoie : %s\n", get_next_line(fd));
	return (0);
}
