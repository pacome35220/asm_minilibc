/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strncmp
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

void	*handle;
int	(*my_strncmp)(const char*, const char*, size_t);

Test(utils, simple_strncmp)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("hello");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp2)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 20) == (*my_strncmp)(str, str2, 20));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp3)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour2");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, good_strncmp4)
{
	char	*str = strdup("bonjour2");
	char	*str2 = strdup("bonjour");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strncmp)
{
	char	*str = strdup("One more test!");
	char	*str2 = strdup("One more");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 8) == (*my_strncmp)(str, str2, 8));
	dlclose(handle);
	free(str);
}

Test(utils, not_good_strncmp2)
{
	char	*str = strdup("One More Test!");
	char	*str2 = strdup("One more");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 8) == (*my_strncmp)(str, str2, 8));
	cr_assert(strncmp(str, str2, 16) == (*my_strncmp)(str, str2, 16));
	dlclose(handle);
	free(str);
}

Test(utils, not_0_check)
{
	char	*str = strdup(" ");
	char	*str2 = strdup("");

	assert(str && str2);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
	cr_assert(strncmp(str, str2, 0) == (*my_strncmp)(str, str2, 0));
	dlclose(handle);
	free(str);
}
