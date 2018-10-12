/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test memcpy
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

void	*handle;
void	*(*my_memcpy)(void*, const void *, size_t);

Test(utils, simple_memcpy)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hellooo");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_memcpy = dlsym(handle, "memcpy");
	assert(!dlerror());
	str = (*my_memcpy)(str, str2, strlen(str));
	cr_assert(strcmp(str, str2) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, simple_memcpy_zero_char)
{
	char	*str = strdup("bonjour");
	char	*str_sys = strdup("bonjour");
	char	*str2 = strdup("hellooo");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_memcpy = dlsym(handle, "memcpy");
	assert(!dlerror());
	str = (*my_memcpy)(str, str2, 0);
	str_sys = memcpy(str_sys, str2, 0);
	cr_assert(strcmp(str, str_sys) == 0);
	dlclose(handle);
	free(str);
}
