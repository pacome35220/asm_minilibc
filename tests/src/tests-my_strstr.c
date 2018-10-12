/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strstr test
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

void	*handle;
char	*(*my_strstr)(const char*, const char*);

Test(utils, simple_strstr)
{
	char	*str = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
	ret_sys = strstr(str, "jour");
	my_ret = (*my_strstr)(str, "jour");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_not_found)
{
	char	*str = strdup("bonjour");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
	my_ret = (*my_strstr)(str, "bite");
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_empty_string)
{
	char	*str = strdup("");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
	my_ret = (*my_strstr)(str, "bite");
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_one_char)
{
	char	*str = strdup("z");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
	my_ret = (*my_strstr)(str, "z");
	char	*test;
	test = strstr(str, "z");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_two_empty)
{
	char	*str = strdup("");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
	my_ret = (*my_strstr)(str, "");
	char	*test;
	test = strstr(str, "");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_second_empty)
{
	char	*str = strdup("bonjour");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
	my_ret = (*my_strstr)(str, "");
	char	*test;
	test = strstr(str, "");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}
