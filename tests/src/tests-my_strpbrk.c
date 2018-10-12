/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strpbrk tests
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

void	*handle;
char	*(*my_strpbrk)(const char*, const char*);

Test(utils, simple_strpbrk)
{
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	assert(!dlerror());
	ret_sys = strpbrk(str, "jour");
	my_ret = (*my_strpbrk)(str2, "jour");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strpbrk_not_found)
{
	void	*handle;
	char	*(*my_strpbrk)(const char*,const char*);
	char	*str = strdup("bonjour");
	char	*str2 = strdup("bonjour");
	char	*my_ret;
	char	*sys;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	assert(!dlerror());
	sys = strpbrk(str2, "iteb");
	my_ret = (*my_strpbrk)(str, "iteb");
	cr_assert(strcmp(sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strpbrk_empty_string)
{
	char	*str = strdup("");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	assert(!dlerror());
	my_ret = (*my_strpbrk)(str, "bite");
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strpbrk_one_char)
{
	char	*str = strdup("z");
	char	*my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strpbrk = dlsym(handle, "strpbrk");
	assert(!dlerror());
	my_ret = (*my_strpbrk)(str, "z");
	char	*test;
	test = strpbrk(str, "z");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}
