/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:41 by raulp             #+#    #+#             */
/*   Updated: 2025/12/10 14:48:02 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
if (!s) // <--- ESTO ES LO QUE TE FALTA Y LO QUE CAUSA EL SEGFAULT
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(len1 + len2 + 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (i < len1)
		{
			p[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (j < len2)
		{
			p[i + j] = s2[j];
			j++;
		}
	}
	p[i + j] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if(!s)
		return (NULL);
	i = 0;
	while ((unsigned char)s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *string)
{
	size_t	i;
	size_t	len;
	char	*arr;
	if (!string)
	{
		arr = malloc(1);
		if (!arr)
			return (NULL);
		arr[0] = '\0';
		return (arr);
	}
	i = 0;
	len = ft_strlen(string);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	while (string[i])
	{
		arr[i] = string[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
