/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strcmp
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
int	(*my_strcmp)(const char*, const char*);
char	*str;
char	*str2;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strcmp = dlsym(handle, "strcmp");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
	free(str2);
}

Test(utils, empty1_strcmp, .init = init, .fini = fini)
{
	str = strdup("");
	str2 = strdup("hello");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, empty2_strcmp, .init = init, .fini = fini)
{
	str = strdup("deded");
	str2 = strdup("");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, both_empty_strcmp, .init = init, .fini = fini)
{
	str = strdup("");
	str2 = strdup("");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, both_1_char_strcmp, .init = init, .fini = fini)
{
	str = strdup("a");
	str2 = strdup("a");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, simple_strcmp, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("hello");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, good_strcmp, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("bonjour");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, not_good_strcmp, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("bonjour23243242");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}

Test(utils, not_good_strcmp2, .init = init, .fini = fini)
{
	str = strdup("bonjour221332213");
	str2 = strdup("bonjour");
	assert(str && str2);
	cr_assert(strcmp(str, str2) == (*my_strcmp)(str, str2));
}
