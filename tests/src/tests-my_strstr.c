/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strstr test
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
char	*(*my_strstr)(const char*, const char*);
char	*str;
char	*ret_sys;
char	*my_ret;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strstr = dlsym(handle, "strstr");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
}

Test(utils, simple_strstr, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	ret_sys = strstr(str, "jour");
	my_ret = (*my_strstr)(str, "jour");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strstr_not_found, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	my_ret = (*my_strstr)(str, "bite");
	cr_assert(my_ret == NULL);
}

Test(utils, strstr_empty_string, .init = init, .fini = fini)
{
	str = strdup("");
	assert(str);
	my_ret = (*my_strstr)(str, "bite");
	cr_assert(my_ret == NULL);
}

Test(utils, strstr_one_char, .init = init, .fini = fini)
{
	str = strdup("z");
	assert(str);
	my_ret = (*my_strstr)(str, "z");
	ret_sys = strstr(str, "z");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strstr_two_empty, .init = init, .fini = fini)
{
	str = strdup("");
	assert(str);
	my_ret = (*my_strstr)(str, "");
	ret_sys = strstr(str, "");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strstr_second_empty, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	my_ret = (*my_strstr)(str, "");
	ret_sys = strstr(str, "");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}
