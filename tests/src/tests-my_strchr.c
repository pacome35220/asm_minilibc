/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strchr tests
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

void	*handle;
char	*(*my_strchr)(char*, int);

Test(utils, simple_strchr)
{
	char	*str = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	assert(!dlerror());
	ret_sys = strchr(str, 'j');
	my_ret = (*my_strchr)(str, 'j');
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_not_found)
{
	char	*str = strdup("bonjour");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	assert(!dlerror());
	my_ret = (*my_strchr)(str, 'z');
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_empty_string)
{
	char	*str = strdup("");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	assert(!dlerror());
	my_ret = (*my_strchr)(str, 'z');
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_one_char)
{
	char	*str = strdup("z");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	assert(!dlerror());
	my_ret = (*my_strchr)(str, 'z');
	char	*test;
	test = strchr(str, 'z');
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_zero)
{
	char	*my_ret;
	char	*test;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	assert(!dlerror());
	test = strchr("bonjour", 0);
	my_ret = (*my_strchr)("bonjour", 0);
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
}
