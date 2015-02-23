/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 12:45:25 by jspezia           #+#    #+#             */
/*   Updated: 2014/03/13 13:56:54 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static char	*proper_join(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = (s1) ? ft_strlen(s1) : 0;
	s2_len = ft_strlen(s2);
	result = ft_strnew(s1_len + s2_len);
	if (result)
	{
		if (s1)
			ft_memcpy(result, s1, s1_len);
		ft_memcpy(result + s1_len, s2, s2_len);
	}
	if (s1)
		ft_strdel(&s1);
	return (result);
}

static int	cut_at_newline(char **save_buff, char **line)
{
	char	*delimiter;

	if ((delimiter = ft_strchr(*save_buff, '\n')))
	{
		*line = ft_strsub(*save_buff, 0, delimiter - *save_buff);
		ft_strcpy(*save_buff, delimiter + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int			bytes_read;
	char		buff[BUFF_SIZE + 1];
	static char	*save_buff = NULL;

	if (save_buff && cut_at_newline(&save_buff, line))
		return (1);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		save_buff = proper_join(save_buff, buff);
		if (cut_at_newline(&save_buff, line))
			return (1);
	}
	if (bytes_read < 0)
		return (-1);
	if (save_buff && *save_buff)
	{
		*line = ft_strdup(save_buff);
		ft_strdel(&save_buff);
		return (1);
	}
	if (save_buff)
		ft_strdel(&save_buff);
	return (0);
}
