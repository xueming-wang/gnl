/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:28:35 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/26 23:36:43 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	tab = (char *)malloc(sizeof(char) * len);
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (s1 && i < len && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2 && i < len && s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free((char *)s1);
	return (tab);
}
