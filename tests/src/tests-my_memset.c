/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test memset
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

void	*handle;
void	*(*my_memset)(char*, int, size_t);

Test(utils, short_memset)
{
	char	*str = strdup("bonjour");

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_memset = dlsym(handle, "memset");
	assert(!dlerror());
	str = (*my_memset)(str, 'a', strlen(str));
	cr_assert(strcmp(str, "aaaaaaa") == 0);
	dlclose(handle);
	free(str);
}

Test(utils, long_memset)
{
	char	*str = strdup("bonjourrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr");

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_memset = dlsym(handle, "memset");
	assert(!dlerror());
	str = (*my_memset)(str, 'a', strlen(str));
	cr_assert(strcmp(str, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == 0);
	dlclose(handle);
	free(str);
}
