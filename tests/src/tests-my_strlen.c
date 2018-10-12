/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strlen
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <dlfcn.h>

void	*handle;
size_t	(*my_strlen)(char*);

Test(utils, simple_strlen)
{
	char	*str = strdup("bonjour");

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strlen = dlsym(handle, "strlen");
	assert(!dlerror());
	cr_assert(strlen(str) == (*my_strlen)(str));
	dlclose(handle);
	free(str);
}

Test(utils, strlen_empty_string)
{
	char	*str = strdup("");

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strlen = dlsym(handle, "strlen");
	assert(!dlerror());
	cr_assert(strlen(str) == (*my_strlen)(str));
	dlclose(handle);
	free(str);
}
