/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strncmp
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
int	(*my_strncmp)(const char*, const char*, size_t);
char	*str;
char	*str2;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strncmp = dlsym(handle, "strncmp");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
	free(str2);
}

Test(utils, simple_strncmp, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("hello");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
}

Test(utils, good_strncmp, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("bonjour");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
}

Test(utils, good_strncmp2, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("bonjour");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 20) == (*my_strncmp)(str, str2, 20));
}

Test(utils, good_strncmp3, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("bonjour2");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
}

Test(utils, good_strncmp4, .init = init, .fini = fini)
{
	str = strdup("bonjour2");
	str2 = strdup("bonjour");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 5) == (*my_strncmp)(str, str2, 5));
}

Test(utils, not_good_strncmp, .init = init, .fini = fini)
{
	str = strdup("One more test!");
	str2 = strdup("One more");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 8) == (*my_strncmp)(str, str2, 8));
}

Test(utils, not_good_strncmp2, .init = init, .fini = fini)
{
	str = strdup("One More Test!");
	str2 = strdup("One more");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 8) == (*my_strncmp)(str, str2, 8));
	cr_assert(strncmp(str, str2, 16) == (*my_strncmp)(str, str2, 16));
}

Test(utils, not_0_check, .init = init, .fini = fini)
{
	str = strdup(" ");
	str2 = strdup("");
	assert(str && str2);
	cr_assert(strncmp(str, str2, 0) == (*my_strncmp)(str, str2, 0));
}
