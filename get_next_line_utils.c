/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:29:46 by fheaton-          #+#    #+#             */
/*   Updated: 2021/02/22 16:34:28 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*s1;
	unsigned char		*s2;

	if (str1 == str2 || n == 0)
		return (str1);
	if (str1 < str2)
	{
		s1 = (unsigned char *)str1;
		s2 = (unsigned char *)str2;
		while (n--)
			*s1++ = *s2++;
	}
	else
	{
		s1 = (unsigned char *)str1 + (n - 1);
		s2 = (unsigned char *)str2 + (n - 1);
		while (n--)
			*s1-- = *s2--;
	}
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(str = malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str + len1, (char *)s2, len2 + 1);
	str[len1 + len2 + 1] = '\0';
	return (str);
}

int			has_line_break(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		if (str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}
