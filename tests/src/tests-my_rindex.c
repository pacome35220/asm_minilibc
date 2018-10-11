/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** rindex tests
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>

#include <dlfcn.h>

Test(utils, simple_rindex)
{
	void	*handle;
	char	*(*my_rindex)(char*, int);
	char	*error;
	char	*str = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_rindex = dlsym(handle, "rindex");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	ret_sys = rindex(str, 'j');
	my_ret = (*my_rindex)(str, 'j');
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, rindex_not_found)
{
	void	*handle;
	char	*(*my_rindex)(char*, int);
	char	*error;
	char	*str = strdup("bonjour");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_rindex = dlsym(handle, "rindex");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_rindex)(str, 'z');
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, rindex_empty_string)
{
	void	*handle;
	char	*(*my_rindex)(char*, int);
	char	*error;
	char	*str = strdup("");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_rindex = dlsym(handle, "rindex");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_rindex)(str, 'z');
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, rindex_one_char)
{
	void	*handle;
	char	*(*my_rindex)(char*, int);
	char	*error;
	char	*str = strdup("z");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_rindex = dlsym(handle, "rindex");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_rindex)(str, 'z');
	char	*test;
	test = rindex(str, 'z');
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}
