/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:38:43 by patferna          #+#    #+#             */
/*   Updated: 2024/12/05 15:22:55 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Para read()
#include <stdlib.h>  // Para malloc() y free()
#include <string.h>  // Para ft_strchr() y ft_substr()
#include <stdio.h>   // Para perror()
#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s && s[len]) len++;
    return len;
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t s1_len = ft_strlen(s1), s2_len = ft_strlen(s2);
    char *result = malloc(s1_len + s2_len + 1);
    if (!result) return NULL;
    if (s1) while (*s1) *result++ = *s1++;
    if (s2) while (*s2) *result++ = *s2++;
    *result = '\0';
    return result - (s1_len + s2_len);
}

char *get_next_line(int fd)
{
    static char *save;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    if (!save) save = malloc(1); if (!save) return NULL;
    save[0] = '\0';

    while (1)
    {
        if (ft_strchr(save, '\n')) 
            return ft_substr(save, 0, ft_strchr(save, '\n') - save + 1);

        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0 || (bytes_read == 0 && !*save)) return NULL;

        buffer[bytes_read] = '\0';
        save = ft_strjoin(save, buffer);
        if (!save) return NULL;
    }
}





/*
char	*initialize_save(void)
{
	char	*save;

	save = calloc(1,1);
	if (!save)
		return (NULL);
	save[0] = '\0';
	return (save);
}

int	handle_read_error(ssize_t bytes_read, char **save)
{
	if (bytes_read < 0)
	{
		free(*save);
		*save = NULL;
		return (1);
	}
	return (0);
}

char	*join_and_free(char *save, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(save, buffer);
	if (!tmp) 
	{
		free(save);
		return (NULL);
	}
	free(save);
	return (tmp);
}
char	*extract_line(char **save)
{
	char	*line;
	char	*newline_pos;
	char	*rest;
	size_t	len;

	newline_pos = ft_strchr(*save, '\n');
	if (!newline_pos) // Si no hay '\n', devuelve todo y limpia save
		return (finalize_save(save));

	len = newline_pos - *save + 1; // Longitud hasta '\n' incluido
	line = ft_substr(*save, 0, len);
	if (!line)
		return (NULL);

	rest = ft_strdup(newline_pos + 1); // Guarda el resto del buffer
	free(*save);
	*save = rest;
	return (line);
}

char	*finalize_save(char **save)
{
	char	*line;

	line = NULL;
	if (*save && **save != '\0')
		line = ft_strdup(*save);
	free(*save);
	*save = NULL;
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (!save)
		save = initialize_save();
	if (!save)
		return (NULL);
	while (1)
	{
		if (ft_strchr(save, '\n')) // Se revisa antes de leer más
			return (extract_line(&save));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (handle_read_error(bytes_read, &save))
			return (NULL);
		if (bytes_read == 0)
			return (finalize_save(&save));
		buffer[bytes_read] = '\0';
		save = join_and_free(save, buffer);
		if (!save) // Si la concatenación falló, devolver NULL
			return (NULL);
	}
}*/
//-----------------------------------------------------------------------
/*
char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (!save)

		save = initialize_save();
	if (!save)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (handle_read_error(bytes_read, &save))
			return (NULL);
		if (bytes_read == 0)
			return (finalize_save(&save));
		buffer[bytes_read] = '\0';
		save = join_and_free(save, buffer);
		if (ft_strchr(save, '\n'))
		{
			char *line = extract_line(&save);
			if (!line) 
				return (NULL);
			return (line);
		}
	}
}
*/
