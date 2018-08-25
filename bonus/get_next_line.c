/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *my_strcat(char *dest, char *src)
{
	size_t i = 0;
	size_t len = ((dest ? strlen(dest) : 0) + (src ? strlen(src) : 0));
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return (NULL);
	if (dest != NULL)
		for (; dest[i] != '\0'; i++)
			new[i] = dest[i];
	if (src != NULL)
		for (; *src != '\0'; i++, src++)
			new[i] = *src;
	new[i] = '\0';
	free(dest);
	return (new);
}

char *my_dup(char *src, size_t n, char *tofree)
{
	size_t i = 0;
	size_t len = (src ? strlen(src) : 0);
	char *new_str;

	if (!(new_str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	for (; i < n && src[i] != '\0'; i++)
		new_str[i] = src[i];
	new_str[i] = '\0';
	free(tofree);
	return (new_str);
}

ssize_t check_back_n(char *str)
{
	if (!str)
		return (-1);
	for (size_t j = 0; str[j] != '\0'; j++)
		if (str[j] == '\n')
			return (j);
	return (-1);
}

char *get_next_line(int fd)
{
	ssize_t size = 0;
	ssize_t pos_back_n = 0;
	char buffer[BUFSIZ + 1];
	static char *tmp = NULL;
	char *rest_line = NULL;

	if ((pos_back_n = check_back_n(tmp)) == -1) {
		if ((size = read(fd, buffer, BUFSIZ)) > 0) {
			buffer[size] = '\0';
			tmp = my_strcat(tmp, buffer);
			return (*buffer == '\0' ? NULL : get_next_line(fd));
		}
		if (!tmp || *tmp == '\0')
			return (free(tmp), tmp = NULL, NULL);
		rest_line = my_dup(tmp, strlen(tmp), tmp);
		tmp = NULL;
		return (rest_line);
	}
	rest_line = my_dup(tmp, pos_back_n, NULL);
	tmp = my_dup(tmp + pos_back_n + 1, strlen(tmp + pos_back_n), tmp);
	return (rest_line);
}
