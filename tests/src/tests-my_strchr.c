/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strchr tests
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

Test(utils, simple_strchr)
{
	void	*handle;
	char	*(*my_strchr)(char*, int);
	char	*error;
	char	*str = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	ret_sys = strchr(str, 'j');
	my_ret = (*my_strchr)(str, 'j');
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_not_found)
{
	void	*handle;
	char	*(*my_strchr)(char*, int);
	char	*error;
	char	*str = strdup("bonjour");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strchr)(str, 'z');
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_empty_string)
{
	void	*handle;
	char	*(*my_strchr)(char*, int);
	char	*error;
	char	*str = strdup("");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strchr)(str, 'z');
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_one_char)
{
	void	*handle;
	char	*(*my_strchr)(char*, int);
	char	*error;
	char	*str = strdup("z");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strchr)(str, 'z');
	char	*test;
	test = strchr(str, 'z');
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strchr_zero)
{
	void	*handle;
	char	*(*my_strchr)(char*, int);
	char	*error;
	char	*my_ret;
	char	*test;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strchr = dlsym(handle, "strchr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	test = strchr("bonjour", 0);
	my_ret = (*my_strchr)("bonjour", 0);
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
}
