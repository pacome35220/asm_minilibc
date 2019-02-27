/*
** EPITECH PROJECT, 2018
** syscall_asm_generator
** File description:
** syscall_asm_generator
*/

#include <assert.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *get_next_line(int fd);

#define	FLAGS		(O_CREAT | O_RDWR | O_TRUNC)
#define	MODE		(0664)
#define SKIP		("#define __NR_")

const char *file = "\tglobal\t%s:function\n\tsection\t.text\n\n%s:\n\tmov\trax, %d\n\tsyscall\n\tret\n";

char *my_snprintf(const char *format, ...)
{
	va_list ap;
	char *new;
	int len;

	if (!format)
		return NULL;
	va_start(ap, format);
	len = vsnprintf(NULL, 0, format, ap);
	if (len < 0)
		return NULL;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return NULL;
	va_end(ap);
	va_start(ap, format);
	vsnprintf(new, len + 1, format, ap);
	va_end(ap);
	return new;
}

void create_asm_file(char *syscall_name, int i)
{
	char *buffer;
	char *filename = my_snprintf("./syscall/%s.s", syscall_name);
	int fd = open(filename, FLAGS, MODE);

	assert(fd != -1);
	buffer = my_snprintf(file, syscall_name, syscall_name, i);
	write(fd, buffer, strlen(buffer));
}

int main(void)
{
	char *line;
	int fd = open("/usr/include/asm/unistd_64.h", O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "mdr c quoi ton os de mort\n");
		return 1;
	}
	for (int i = 0; (line = get_next_line(fd)) != NULL; i++) {
		if (i < 3 || strncmp(line, SKIP, sizeof(SKIP) - 1))
			continue;
		*strrchr(line, ' ') = '\0';
		if (strcmp("times", line + sizeof(SKIP)))
			create_asm_file(line + sizeof(SKIP) - 1, i - 3);
		free(line);
	}
	return 0;
}
