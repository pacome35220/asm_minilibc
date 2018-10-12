/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strcasecmp test
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

void	*handle;
int	(*my_strcasecmp)(const char*, const char*);

Test(utils, simple_strcasecmp)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hello");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	assert(!dlerror());
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, good_strcasecmp)
{
	char	*str = strdup("boNJOur");
	char	*str2 = strdup("bonjour");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	assert(!dlerror());
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcasecmp)
{
	char	*str = strdup("bonJouR");
	char	*str2 = strdup("bonjour2");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	assert(!dlerror());
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strcasecmp2)
{
	char	*str = strdup("bonjour2");
	char	*str2 = strdup("bonJouR");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	assert(!dlerror());
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
	dlclose(handle);
	free(str);
}
