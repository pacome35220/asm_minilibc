/*
** EPITECH PROJECT, 2018
** syscall_asm_generator
** File description:
** syscall_asm_generator
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define	FLAGS		(O_CREAT | O_RDWR | O_TRUNC)
#define	MODE		(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

const char *file = "\tglobal\t%s:function\n\tsection\t.text\n\n%s:\n\tmov\trax, %d\n\tsyscall\n\tret";

char *my_snprintf(const char *format, ...)
{
	va_list ap;
	char *new;
	int len;

	if (!format)
		return (NULL);
	va_start(ap, format);
	if ((len = vsnprintf(NULL, 0, format, ap)) < 0)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	va_end(ap);
	va_start(ap, format);
	vsnprintf(new, len + 1, format, ap);
	va_end(ap);
	return (new);
}

void create_asm_file(char *syscall_name, int i)
{
	char *buffer;
	char *filename = my_snprintf("./src/syscall/%s.c", file);
	int fd = open(filename, FLAGS, MODE);

	buffer = my_snprintf(file, syscall_name, syscall_name, i);

}

int main()
{
	int fd = open("", );
	return 0;
}
