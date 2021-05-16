/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:51 by aazevedo          #+#    #+#             */
/*   Updated: 2021/03/11 11:59:52 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	new_str[s1_len + i] = 0;
	return (new_str);
}

int		ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	src_i;
	int	src_len;

	if (!dst)
		return (-1);
	src_i = 0;
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src_i < src_len && src_i + 1 < dstsize)
	{
		dst[src_i] = src[src_i];
		src_i++;
	}
	if (dstsize > 0)
		dst[src_i] = '\0';
	return (src_len);
}

char	*ft_substr(char const *s, size_t start, int len)
{
	int		i;
	int		substr_max_len;
	char	*substr;

	i = 0;
	substr_max_len = ft_strlen(s);
	if (len < substr_max_len)
		substr_max_len = len;
	substr = (char *)malloc(sizeof(char) * (substr_max_len + 1));
	if (!substr)
		return (0);
	while (start < ft_strlen(s) && i < substr_max_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}
