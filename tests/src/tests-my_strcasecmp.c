/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strcasecmp test
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

void	*handle;
int	(*my_strcasecmp)(const char*, const char*);
char	*str;
char	*str2;

static void init(void)
{
	handle = dlopen("./libasm.so", RTLD_LAZY);
	assert(handle);
	my_strcasecmp = dlsym(handle, "strcasecmp");
	assert(!dlerror());
}

static void fini(void)
{
	dlclose(handle);
	free(str);
	free(str2);
}

Test(utils, simple, .init = init, .fini = fini)
{
	str = strdup("bonjour");
	str2 = strdup("hello");
	assert(str && str2);
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
}

Test(utils, good, .init = init, .fini = fini)
{
	str = strdup("boNJOur");
	str2 = strdup("bonjour");
	assert(str && str2);
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
}

Test(utils, not_good, .init = init, .fini = fini)
{
	str = strdup("bonJouR");
	str2 = strdup("bonjour2");
	assert(str && str2);
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
}

Test(utils, not_good2, .init = init, .fini = fini)
{
	str = strdup("bonjour2");
	str2 = strdup("bonJouR");
	assert(str && str2);
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
}

Test(utils, alphabet, .init = init, .fini = fini)
{
	str = strdup("azertyuiopqsdfghjklmwxcvbn");
	str2 = strdup("AZERTYUIOPQSDFGHJKLMWXCVBN");
	assert(str && str2);
	cr_assert(strcasecmp(str, str2) == (*my_strcasecmp)(str, str2));
}
