/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:23:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/03/26 21:56:45 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include "libc.h"

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char        *ft_strjoin(char const *s1, char const *s2);

#endif
