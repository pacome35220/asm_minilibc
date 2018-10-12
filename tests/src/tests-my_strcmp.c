/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strcmp
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

void	*handle;
int	(*my_strcmp)(const char*, const char*);

Test(utils, simple_strcmp)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hello");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	assert(!dlerror());
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, good_strcmp)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	assert(!dlerror());
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcmp)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour2");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	assert(!dlerror());
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcmp2)
{
	char	*str = strdup("bonjour2");
	char	*str2 = strdup("bonjour");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcmp = dlsym(handle, "strcmp");
	assert(!dlerror());
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
	dlclose(handle);
	free(str);
}
