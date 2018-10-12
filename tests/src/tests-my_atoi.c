/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** atoi test
*/

#include <assert.h>
#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

void	*handle;
int	(*my_atoi)(const char *);

Test(utils, 42)
{
	char *str = strdup("42");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	printf("%d ; %d\n", ret_sys, my_ret);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(utils, 14324)
{
	char *str = strdup("14324");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(utils, 0)
{
	char *str = strdup("0");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(utils, minus1)
{
	char *str = strdup("-1");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(utils, minus42)
{
	char *str = strdup("-42");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(utils, overflow)
{
	char *str = strdup("234567765432456543");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}

Test(utils, underflow)
{
	char *str = strdup("-234567765432456543");
	int ret_sys;
	int my_ret;

	assert(str);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_atoi = dlsym(handle, "atoi");
	assert(!dlerror());
	ret_sys = atoi(str);
	my_ret = (*my_atoi)(str);
	cr_assert(ret_sys == my_ret);
	dlclose(handle);
	free(str);
}
