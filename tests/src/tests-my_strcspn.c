/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strcspn
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

void    *handle;
int    (*my_strcspn)(const char*, const char*);

Test(strcspn, simple_strcspn)
{
	char    *str = strdup("bonjour");
	char    *str2 = strdup("o");
	int    ret_sys;
	int    my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, simple_strcspn2)
{
	char    *str = strdup("bonjour");
	char    *str2 = strdup("or");
	int    ret_sys;
	int    my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, simple_strcspn3)
{
	char    *str = strdup("bonjour");
	char    *str2 = strdup("slt");
	int    ret_sys;
	int    my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, first_empty)
{
	char    *str = strdup("");
	char    *str2 = strdup("abcd");
	int    ret_sys;
	int    my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, second_empty)
{
	char    *str = strdup("bonjour");
	char    *str2 = strdup("");
	int    ret_sys;
	int    my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(strcspn, both_empty)
{
	char    *str = strdup("");
	char    *str2 = strdup("");
	int    ret_sys;
	int    my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
	ret_sys = strcspn(str, str2);
	my_ret = (*my_strcspn)(str, str2);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}
