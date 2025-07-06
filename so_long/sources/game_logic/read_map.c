/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:49:48 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/24 19:42:49 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

// Main function to read the content from a file into a string
char	*read_file_content(char *str)
{
	int		fd;
	char	*file_content;

	fd = open_file_for_reading(str);
	if (fd == -1)
		return (NULL);
	file_content = read_from_file(fd);
	if (!file_content)
		return (NULL);
	if (!close_file(fd, file_content))
		return (NULL);
	return (file_content);
}

// Opens the file for reading, returns -1 on error
int	open_file_for_reading(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\nOpening the file failed\n", 2);
	return (fd);
}

char	*read_from_file(int fd)
{
	char	*txt;
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	txt = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(txt), NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = txt;
		txt = ft_strjoin_so_long(txt, buffer);
		free(tmp);
		if (!txt)
			return (free(buffer), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1)
		return (free(txt), ft_putstr_fd("Error\nMapread fail\n", 2), NULL);
	return (txt);
}

// Closes the file, returns 1 on success, 0 on failure
int	close_file(int fd, char *txt)
{
	if (close(fd) == -1)
	{
		free(txt);
		ft_putstr_fd("Error\nClosing the file failed\n", 2);
		return (FAIL);
	}
	return (SUCCESS);
}
