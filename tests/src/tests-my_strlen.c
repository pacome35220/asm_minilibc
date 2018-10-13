/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strlen
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
size_t	(*my_strlen)(char*);
char	*str;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strlen = dlsym(handle, "strlen");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
}

Test(utils, simple_strlen, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	assert(str);
	cr_assert(strlen(str) == (*my_strlen)(str));
}

Test(utils, strlen_empty_string, .init = init, .fini = fini)
{
	str = strdup("");
	assert(str);
	cr_assert(strlen(str) == (*my_strlen)(str));
}
