/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalbrid <mdalbrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:50:03 by mdalbrid          #+#    #+#             */
/*   Updated: 2020/12/24 22:22:50 by mdalbrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t p;

	p = 0;
	while (s[p] != '\0')
		p++;
	return (p);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*newstr;

	len = ft_strlen(s) + 1;
	if (!(newstr = (char*)malloc(len)))
		return (NULL);
	while (--len >= 0)
		newstr[len] = s[len];
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	res = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;
	char			*b;

	a = (unsigned char)c;
	b = (char*)s;
	if (a == 0)
		return (b);
	while (*b)
	{
		if (*b == c)
			return (b);
		b++;
	}
	return (NULL);
}
