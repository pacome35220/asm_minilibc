/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** test strcspn
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void	*handle;
size_t	(*my_strcspn)(const char*, const char*);
char	*str;
char	*str2;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strcspn = dlsym(handle, "strcspn");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
	free(str2);
}

Test(strcspn, simple_strcspn, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("o");
	assert(str && str2);
	cr_assert(strcspn(str, str2) == (*my_strcspn)(str, str2));
}

Test(strcspn, simple_strcspn2, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("or");
	assert(str && str2);
	cr_assert(strcspn(str, str2) == (*my_strcspn)(str, str2));
}

Test(strcspn, simple_strcspn3, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("slt");
	assert(str && str2);
	cr_assert(strcspn(str, str2) == (*my_strcspn)(str, str2));
}

Test(strcspn, first_empty, .init = init, .fini = fini)
{
	str = strdup("");
	str2 = strdup("abcd");
	assert(str && str2);
	cr_assert(strcspn(str, str2) == (*my_strcspn)(str, str2));
}

Test(strcspn, second_empty, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("");
	assert(str && str2);
	cr_assert(strcspn(str, str2) == (*my_strcspn)(str, str2));
}

Test(strcspn, both_empty, .init = init, .fini = fini)
{
	str = strdup("");
	str2 = strdup("");
	assert(str && str2);
	cr_assert(strcspn(str, str2) == (*my_strcspn)(str, str2));
}
