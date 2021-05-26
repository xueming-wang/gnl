/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:23:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/26 23:48:35 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# define FD_MAX_SIZE 256

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char        *ft_strjoin(char const *s1, char const *s2);

#endif
