/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test memcpy
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

Test(utils, simple_memcpy)
{
	void	*handle;
	void	*(*my_memcpy)(void*, const void *, size_t);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hellooo");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_memcpy = dlsym(handle, "memcpy");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	str = (*my_memcpy)(str, str2, strlen(str));
	cr_assert(strcmp(str, str2) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, simple_memcpy_zero_char)
{
	void	*handle;
	void	*(*my_memcpy)(void*, const void *, size_t);
	char	*error;
	char	*str = strdup("bonjour");
	char	*str_sys = strdup("bonjour");
	char	*str2 = strdup("hellooo");

	if (!str || !str2)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_memcpy = dlsym(handle, "memcpy");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	str = (*my_memcpy)(str, str2, 0);
	str_sys = memcpy(str_sys, str2, 0);
	cr_assert(strcmp(str, str_sys) == 0);
	dlclose(handle);
	free(str);
}
