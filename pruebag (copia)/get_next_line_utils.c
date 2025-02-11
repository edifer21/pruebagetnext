/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:37:26 by patferna          #+#    #+#             */
/*   Updated: 2024/12/05 14:30:56 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Para read()
#include <stdlib.h>  // Para malloc() y free()
#include <string.h>  // Para memcpy()
#include <stdio.h>   // Para perror()
#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s) {
    size_t len = 0;
    if (!s)
        return 0;
    while (s[len])
        len++;
    return len;
}

char *ft_strjoin(const char *s1, const char *s2) {
    size_t s1_len = ft_strlen(s1), s2_len = ft_strlen(s2);
    char *ptr = malloc(s1_len + s2_len + 1);
    if (!ptr)
        return NULL;
    if (s1)
        while (*s1)
            *ptr++ = *s1++;
    if (s2)
        while (*s2)
            *ptr++ = *s2++;
    *ptr = '\0';
    return ptr - (s1_len + s2_len);
}

char *ft_strchr(const char *s, int c) {
    if (!s)
        return NULL;
    while (*s) {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return c == '\0' ? (char *)s : NULL;
}

char *ft_substr(const char *s, unsigned int start, size_t len) {
    size_t s_len = ft_strlen(s);
    if (!s || start >= s_len)
        return NULL;
    if (len > s_len - start)
        len = s_len - start;
    char *sub = malloc(len + 1);
    if (!sub)
        return NULL;
    for (size_t i = 0; i < len; i++)
        sub[i] = s[start + i];
    sub[len] = '\0';
    return sub;
}


/*
----------------------------------------------------------------

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptd;
	unsigned char	*pts;

	if (!dest || !src)
		return (NULL);
	ptd = (unsigned char *) dest;
	pts = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ptd[i] = pts[i];
		i++;
	}
	return ((void *)dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	ptr_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr_len = s1_len + s2_len;
	ptr = malloc(ptr_len + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_memcpy(ptr, s1, s1_len);
	if (s2)
		ft_memcpy(ptr + s1_len, s2, s2_len);
	ptr[ptr_len] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (c == '\0' ? (char *)s : NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	char *dup;

	if (!s)
		return (NULL);
	dup = malloc(n + 1);
	if (!dup)
		return NULL;
	ft_memcpy(dup, s, n);
	dup[n] = '\0';
	return dup;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}*/
//-------------------------------------------------------------------------------------------------------

/*
#include <unistd.h>  // Para read()
#include <stdlib.h>  // Para malloc() y free()
#include <string.h>  // Para memcpy()
#include <stdio.h>   // Para perror()
#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptd;
	unsigned char	*pts;

	if (!dest || !src)
		return (NULL);
	ptd = (unsigned char *) dest;
	pts = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ptd[i] = pts[i];
		i++;
	}
	return ((void *)dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
    if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	str2_len;
	size_t	ptr_len;

	
	s1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	ptr_len = s1_len + str2_len;
    	ptr = malloc(((ptr_len) + 1) * sizeof(char));
    if (!ptr)
		return (NULL);
    if (!s1 && !s2)
		return (NULL);
	
	if (s1)
		ft_memcpy (ptr, s1, s1_len);
	if (s2)
		ft_memcpy (ptr + s1_len, s2, str2_len);
	ptr[ptr_len] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = strlen(s) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	a = c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == a)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (a == 0)
	{
		return ((char *) &s[i]);
	}
	return (0);
}



char *ft_strndup(const char *s, size_t n)
{
	char *dup;

	dup =  malloc(n + 1);
	if (!dup)
		return NULL;
	ft_memcpy(dup, s, n);
	dup[n] = '\0';
	return dup;
}
*/