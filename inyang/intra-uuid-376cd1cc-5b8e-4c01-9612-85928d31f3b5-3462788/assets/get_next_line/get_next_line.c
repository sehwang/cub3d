/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:19:38 by inyang            #+#    #+#             */
/*   Updated: 2021/05/17 13:19:43 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_success(char **isremain, char **line)
{
	char	*line_two;
	char	*tmp;
	int		index;

	line_two = *isremain;
	if ((index = ft_line(line_two)) != -1)
	{
		tmp = line_two;
		while (*line_two != '\n')
			line_two++;
		*line_two = '\0';
		*line = ft_strdup_gnl(tmp);
		*isremain = ft_strdup_gnl(line_two + 1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = *isremain;
		*isremain = NULL;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*isremain;
	char		*buf;
	int			reader;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!isremain)
		isremain = ft_strdup_gnl("");
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strchr_gnl(isremain, '\n')
		&& (reader = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[reader] = '\0';
		tmp = ft_strjoin_gnl(isremain, buf);
		free(isremain);
		isremain = tmp;
	}
	free(buf);
	if (reader < 0)
		return (-1);
	return (read_success(&isremain, line));
}
