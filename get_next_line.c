/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:43:40 by xuwang            #+#    #+#             */
/*   Updated: 2021/03/26 22:11:19 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *first_line(char *str)
{
    char *line;
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i] && str[i] != '\n')
            i++;       
    line = (char *)malloc(sizeof(char) * i + 1);
    if (!line)
        return(0);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char  *save_line(char *save)
{
    char *str;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!save)
        return(0);
    while (save[i] && save[i]!= '\n')
        i++;
    if (!save[i])
    {
        free(save);
        return (0);
    }
    str = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
    if(!str)
        return(0);
    i++;
    while (save[i])
    {
        str[j++] = save[i++];
    }
    free(save);
    str[j] = '\0';
    return (str);
}

int     ft_newline(char *save)
{
    int i;

    i = 0;
    if (!save)
        return (0);
    while (save[i])
    {
        if (save[i] == '\n')
            return(1);
        i++;
    }
    return (0);
}

int get_next_line(int fd, char **line)    
{
    char            buf[BUFFER_SIZE + 1];
    int             read_num;
    static char     *save;   // (read的字符串)

    read_num = 1;
    if (fd < 0 || !line || BUFFER_SIZE <= 0) 
      return (-1);
    while (read_num != 0 && !ft_newline(save)) 
    {
        read_num = read(fd, buf, BUFFER_SIZE);
        if (read_num == -1)
            return(-1);
        buf[read_num] = '\0';
        save = ft_strjoin(save, buf); //第一次read的字符串,第二次是第一次\n后面剩的字符 + 第二次读的字符串)
    }
    *line = first_line(save); // read的字符串保存\n前面的字符保存在line；
    save = save_line(save);  // \n后面的字符保存用于第二次链接；
    if (read_num == 0)
        return (0);
    return (1);
}