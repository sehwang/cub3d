/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:47:48 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/14 15:02:26 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isalpha(int c)
{
	if ((65 <= c && 90 >= c) || (97 <= c && 122 >= c))
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t s_len;

	s_len = ft_strlen((char*)src);
	i = 0;
	if (dstsize == 0)
		return (s_len);
	while (i++ + 1 < dstsize && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (s_len);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char			*rtn;
	int				len1;
	int				len2;
	int				i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(rtn = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			rtn[i] = s1[i];
		else
			rtn[i] = s2[i - len1];
		i++;
	}
	rtn[len1 + len2] = '\0';
	free(s1);
	return (rtn);
}

char				*ft_strdup(char *src)
{
	char			*dest;
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dest = (char*)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (i++ < n)
		*dst++ = *sr++;
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_check_extention(char *file, char *extention)
{
	int len_f;
	int len_ex;
	int n;

	len_f = ft_strlen(file);
	len_ex = ft_strlen(extention);
	if (len_f <= len_ex)
		return (-1);
	n = 0;
	while (n < len_ex)
	{
		if (file[len_f - n - 1] != extention[len_ex - n - 1])
			return (-1);
		n++;
	}
	if (file[len_f - n - 1] == '.')
		return (1);
	return (-1);
}
