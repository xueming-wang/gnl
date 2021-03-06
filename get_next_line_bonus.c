/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:43:40 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/30 19:22:56 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*first_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_line(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (save[i])
		str[j++] = save[i++];
	free(save);
	str[j] = '\0';
	return (str);
}

static int	ft_newline(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			read_num;
	static char	*save[FD_MAX_SIZE];

	read_num = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= FD_MAX_SIZE)
		return (-1);
	while (read_num != 0 && !ft_newline(save[fd]))
	{
		read_num = read(fd, buf, BUFFER_SIZE);
		if (read_num == -1)
			return (-1);
		buf[read_num] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	*line = first_line(save[fd]);
	save[fd] = save_line(save[fd]);
	if (read_num == 0)
		return (0);
	return (1);
}
