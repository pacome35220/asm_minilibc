/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strlen
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <dlfcn.h>

Test(utils, simple_strlen)
{
	void	*handle;
	size_t	(*my_strlen)(char*);
	char	*error;
	char	*str = strdup("bonjour");

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strlen = dlsym(handle, "strlen");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strlen(str) == (*my_strlen)(str));
	dlclose(handle);
	free(str);
}

Test(utils, strlen_empty_string)
{
	void	*handle;
	size_t	(*my_strlen)(char*);
	char	*error;
	char	*str = strdup("");

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strlen = dlsym(handle, "strlen");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	cr_assert(strlen(str) == (*my_strlen)(str));
	dlclose(handle);
	free(str);
}
