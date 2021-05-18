/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:36:50 by inyang            #+#    #+#             */
/*   Updated: 2021/03/24 17:57:14 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr_gnl(char *str, char c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	if (s == 0)
		return (s);
	return (0);
}

char		*ft_strjoin_gnl(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!(s1) || !(s2))
		return (NULL);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	i = 0;
	j = -1;
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

size_t		ft_strlen_gnl(const char *str)
{
	int i;

	i = 0;
	while (str[(int)i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup_gnl(const char *src)
{
	char	*result;
	int		i;

	i = 0;
	while (src[i])
		i++;
	result = (char *)malloc(sizeof(char) * i + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int			ft_line(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
