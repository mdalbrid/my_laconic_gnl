/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalbrid <mdalbrid@student.21>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:02:41 by mdalbrid          #+#    #+#             */
/*   Updated: 2020/12/26 04:21:36 by mdalbrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_ost(char **text, char **line)
{
	char	*ptr_new_str;

	if (*text && (ptr_new_str = ft_strchr(*text, '\n')))
	{
		*ptr_new_str++ = '\0';
		*line = *text;
		*text = ft_strdup(ptr_new_str);
		return (1);
	}
	else if (*text)
	{
		*line = *text;
		*text = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*text[1024];
	char			buf[BUFFER_SIZE + 1];
	int				bws;
	char			*tmp;

	if (BUFFER_SIZE < 1 || read(fd, buf, 0) == -1 || !line || fd < 0)
		return (-1);
	if (!text[fd])
		text[fd] = ft_strdup("");
	while ((bws = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bws] = '\0';
		tmp = text[fd];
		text[fd] = ft_strjoin(text[fd], buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_ost(&text[fd], line));
}
