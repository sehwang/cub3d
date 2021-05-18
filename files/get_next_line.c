/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:35:43 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/11 17:38:15 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		idx_newline(char *keep_buf)
{
	int i;

	i = 0;
	while (keep_buf[i])
	{
		if (keep_buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		append_line(char **keep_buf, char **line, int n_idx)
{
	char	*tmp;
	int		len;

	(*keep_buf)[n_idx] = '\0';
	*line = ft_strdup(*keep_buf);
	len = ft_strlen(*keep_buf + n_idx + 1);
	tmp = ft_strdup(*keep_buf + n_idx + 1);
	free(*keep_buf);
	*keep_buf = tmp;
	return (1);
}

int		ft_result(char **keep_buf, char **line, int read_size)
{
	int	n_idx;

	if (read_size < 0)
		return (-1);
	if (*keep_buf && (n_idx = idx_newline(*keep_buf)) >= 0)
		return (append_line(keep_buf, line, n_idx));
	if (!(*keep_buf))
		*line = ft_strdup("");
	else
	{
		*line = *keep_buf;
		*keep_buf = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_len;
	char		buf[BUFFER_SIZE + 1];
	static char	*keep_buf[OPEN_MAX];
	int			n_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = 0;
		keep_buf[fd] = ft_strjoin(keep_buf[fd], buf);
		if ((n_idx = idx_newline(keep_buf[fd])) >= 0)
		{
			append_line(&keep_buf[fd], line, n_idx);
			return (1);
		}
	}
	return (ft_result(&keep_buf[fd], line, read_len));
}
