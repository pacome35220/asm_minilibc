/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** atoi test
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

Test(utils, atoi)
{
	int	(*my_atoi)(const char *);
	void	*handle = dlopen("./libasm.so", RTLD_LAZY);

	assert(handle);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());

	cr_assert(atoi("42") == (*my_atoi)("42"));
	cr_assert(atoi("14333") == (*my_atoi)("14333"));
	cr_assert(atoi("0") == (*my_atoi)("0"));
	cr_assert(atoi("-1") == (*my_atoi)("-1"));
	cr_assert(atoi("-1254234") == (*my_atoi)("-1254234"));
	cr_assert(atoi("243435544444524524") == (*my_atoi)("243435544444524524"));
	cr_assert(atoi("mdr") == (*my_atoi)("mdr"));
	cr_assert(atoi("34234émdr") == (*my_atoi)("34234émdr"));
	cr_assert(atoi("lol34234émdr") == (*my_atoi)("lol34234émdr"));
	dlclose(handle);
}
