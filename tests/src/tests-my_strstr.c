/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** strstr test
*/

#include <criterion/criterion.h>

#include <stdio.h>

#include <dlfcn.h>

Test(utils, simple_strstr)
{
	void	*handle;
	char	*(*my_strstr)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*ret_sys;
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	ret_sys = strstr(str, "jour");
	my_ret = (*my_strstr)(str, "jour");
	cr_assert(strcmp(ret_sys, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_not_found)
{
	void	*handle;
	char	*(*my_strstr)(const char*,const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strstr)(str, "bite");
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_empty_string)
{
	void	*handle;
	char	*(*my_strstr)(const char*, const char*);
	char	*error;
	char	*str = strdup("");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strstr)(str, "bite");
	cr_assert(my_ret == NULL);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_one_char)
{
	void	*handle;
	char	*(*my_strstr)(const char*, const char*);
	char	*error;
	char	*str = strdup("z");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strstr)(str, "z");
	char	*test;
	test = strstr(str, "z");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_two_empty)
{
	void	*handle;
	char	*(*my_strstr)(const char*, const char*);
	char	*error;
	char	*str = strdup("");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strstr)(str, "");
	char	*test;
	test = strstr(str, "");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}

Test(utils, strstr_second_empty)
{
	void	*handle;
	char	*(*my_strstr)(const char*, const char*);
	char	*error;
	char	*str = strdup("bonjour");
	char	*my_ret;

	if (!str)
		exit(84);
	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (!handle)
		exit(84);
	my_strstr = dlsym(handle, "strstr");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
		exit(84);
	}
	my_ret = (*my_strstr)(str, "");
	char	*test;
	test = strstr(str, "");
	cr_assert(strcmp(test, my_ret) == 0);
	dlclose(handle);
	free(str);
}
