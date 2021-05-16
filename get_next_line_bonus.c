/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:00 by aazevedo          #+#    #+#             */
/*   Updated: 2021/03/11 11:59:02 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*s_line[1024];
	int			ret;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) == -1 || !line)
		return (-1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (-1);
	while (find_nl(s_line[fd]) == -1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		s_line[fd] = buf_to_line(s_line[fd], buf);
	}
	s_line[fd] = save_line(s_line[fd], line);
	free(buf);
	buf = NULL;
	if (ret < 0)
		return (-1);
	else if (s_line[fd])
		return (1);
	return (0);
}

char	*save_line(char *s_line, char **line)
{
	int		new_line_i;
	char	*tmp;

	new_line_i = find_nl(s_line);
	if (new_line_i >= 0)
	{
		*line = (char *)ft_calloc(new_line_i + 1, sizeof(char));
		tmp = ft_substr(s_line, new_line_i + 1, ft_strlen(s_line) - new_line_i);
		ft_strlcpy(*line, s_line, new_line_i + 1);
		free(s_line);
		return (tmp);
	}
	else
	{
		*line = ft_strdup(s_line);
		free(s_line);
		return (NULL);
	}
}

char	*buf_to_line(char *s_line, char *buf)
{
	char	*tmp;

	if (s_line)
	{
		tmp = ft_strjoin(s_line, buf);
		free(s_line);
		return (tmp);
	}
	return (ft_strdup(buf));
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	while (i < count * size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

int		find_nl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if ((unsigned char)s[i] == '\n')
			return (i);
		else if (s[i] == 0)
			return (-1);
		i++;
	}
	return (-1);
}
