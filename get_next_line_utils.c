/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:41 by raulp             #+#    #+#             */
/*   Updated: 2025/11/05 10:25:29 by raulp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2 )
{
	size_t	arr1;
	size_t	arr2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	arr1 = ft_strlen(s1);
	arr2 = ft_strlen(s2);
	p = malloc(arr1 + arr2 + 1);
	if (!p)
		return (NULL);
	insert_array(s1, s2, p);
	return (p);
}
