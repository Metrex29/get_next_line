/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulp <raulp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:47:41 by raulp             #+#    #+#             */
/*   Updated: 2025/11/11 13:00:07 by raulp            ###   ########.fr       */
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

static void	write_subs(char const *s, unsigned int start, size_t len, char *p)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (j < len && s[i])
		p[j++] = s[i++];
	p[j] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	arr1;
	char	*p;

	if (!s)
		return (NULL);
	arr1 = ft_strlen (s);
	if (start >= arr1)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	if (len > arr1 - start)
		len = arr1 - start;
	p = malloc (len + 1);
	if (!p)
		return (NULL);
	write_subs (s, start, len, p);
	return (p);
}
