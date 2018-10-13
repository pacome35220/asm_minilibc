/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strpbrk tests
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
char	*(*my_strpbrk)(const char*, const char*);
char	*str;
char	*ret_sys;
char	*my_ret;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strpbrk = dlsym(handle, "strpbrk");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
}

Test(utils, simple_strpbrk, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	ret_sys = strpbrk(str, "jour");
	my_ret = (*my_strpbrk)(str, "jour");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strpbrk_not_found, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	ret_sys = strpbrk(str, "iteb");
	my_ret = (*my_strpbrk)(str, "iteb");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}

Test(utils, strpbrk_empty_string, .init = init, .fini = fini)
{
	str = strdup("");
	assert(str);
	my_ret = (*my_strpbrk)(str, "bite");
	cr_assert(my_ret == NULL);
}

Test(utils, strpbrk_one_char, .init = init, .fini = fini)
{
	str = strdup("z");
	assert(str);
	my_ret = (*my_strpbrk)(str, "z");
	ret_sys = strpbrk(str, "z");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
}
