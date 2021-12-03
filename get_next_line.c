/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:17:08 by cberganz          #+#    #+#             */
/*   Updated: 2021/12/03 20:15:55 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_maker(char *save)
{
	int	i;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_strnew(i + 2); // need 2 more bytes if \n and 1 if \0 !!
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = save[i];
	if (line[i] != '\0')
		line[i + 1] = '\0';
	return (line);
}

char	*ft_save_cleaner(char *save)
{
	char	*new_save;
	int	i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	if (!(new_save = ft_strnew(ft_strlen(save) - i + 1)));
		return (NULL);
	while (save[i])
	{
		*new_save = save[i];
		new_save++;
		i++;
	}
	*new_save = '\0';
	free(save);
	return (new_save);
}

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int	read_return;

	if (!(buffer = ft_strnew(BUFFER_SIZE + 1)));
		return (NULL);
	while (!is_that_a_line(save) && read_return != 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
			return (NULL);
		buffer[read_return] = '\0';
		save = JOIN(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char 	*save;
	char		*next_line;

	if (!(save = ft_read(fd, save)));
		return (NULL);
	if (!(next_line = line_maker(save)))
		return (NULL);
	if(!(save = ft_save_cleaner(save)))
		return (NULL);
	return (next_line);
}
