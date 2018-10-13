/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** rindex tests
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
char	*(*my_rindex)(char*, int);
char	*str;
char	*ret_sys;
char	*my_ret;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_rindex = dlsym(handle, "rindex");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
}

Test(utils, simple_rindex, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	ret_sys = rindex(str, 'j');
	my_ret = (*my_rindex)(str, 'j');
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, rindex_not_found, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	my_ret = (*my_rindex)(str, 'z');
	cr_assert(my_ret == NULL);
}

Test(utils, rindex_empty_string, .init = init, .fini = fini)
{
	str = strdup("");
	assert(str);
	my_ret = (*my_rindex)(str, 'z');
	cr_assert(my_ret == NULL);
}

Test(utils, rindex_one_char, .init = init, .fini = fini)
{
	str = strdup("z");
	assert(str);
	my_ret = (*my_rindex)(str, 'z');
	ret_sys = rindex(str, 'z');
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}
